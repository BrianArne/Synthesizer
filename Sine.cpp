#include <stdio.h>
#include <math.h>
#include <portaudio.h>
#include <iostream>
#include "ScopedPaHandler.hpp"

#define NUM_SECONDS   (5)
#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER  (64)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

#define TABLE_SIZE   (100)

class Sine
{
  public:
    Sine() : stream(0),
             left_phase(0), 
             right_phase(0),
             n_phase(0)
  {
    /* Init. wavetable */
    for( int i=0; i<TABLE_SIZE; i++ )
    {
      sine[i] = (float) sin( ((double)i/(double)TABLE_SIZE) * M_PI * 2. );
    }
  }

    bool open(PaDeviceIndex index)
    {
      //First we set up an output
      PaStreamParameters outputParameters;

      outputParameters.device = index;
      if (outputParameters.device == paNoDevice) {
        return false;
      }

      const PaDeviceInfo* pInfo = Pa_GetDeviceInfo(index);
      if (pInfo != 0)
      {
        printf("Output device name: '%s'\r", pInfo->name);
      }

      outputParameters.channelCount = 1;
      outputParameters.sampleFormat = paFloat32;
      outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
      outputParameters.hostApiSpecificStreamInfo = NULL;

      //This creates the actual stream and where it gets it's data from(this)
      //and its call back function
      //Returns an integer to check for error
      PaError err = Pa_OpenStream(
          &stream,
          NULL, //no input
          &outputParameters,
          SAMPLE_RATE,
          paFramesPerBufferUnspecified,
          paClipOff,
          &Sine::paCallback,
          this
          );

      if (err != paNoError)
      {
        //Failed to open
        return false;
      }

      //Streams provide access to audio hardware
      //Streams request audio from callback methods
      err = Pa_SetStreamFinishedCallback( stream, &Sine::paStreamFinished );

      if (err != paNoError)
      {
        Pa_CloseStream( stream );
        stream = 0;

        return false;
      }

      return true;
    }

    bool close()
    {
      if (stream == 0)
        return false;

      PaError err = Pa_CloseStream( stream );
      stream = 0;

      return (err == paNoError);
    }


    bool start()
    {
      if (stream == 0)
        return false;

      PaError err = Pa_StartStream( stream );

      return (err == paNoError);
    }

    bool stop()
    {
      if (stream == 0)
        return false;

      PaError err = Pa_StopStream( stream );

      return (err == paNoError);
    }

  private:
    /* The instance callback, where we have access to every method/variable in object of class Sine */
    int paCallbackMethod(const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags)
    {
      float *out = (float*)outputBuffer;
      unsigned long i;

      (void) timeInfo;
      (void) statusFlags;
      (void) inputBuffer;

      for( i=0; i<framesPerBuffer; i++ )
      {
        *out++ = 5*sine[left_phase] + 1.5*sine[right_phase] + .2 * sine[n_phase];// + sine[right_phase] + sine[n_phase];
        //*out++ = sine[right_phase];// + sine[right_phase] + sine[n_phase];
        left_phase += 1;
        if (left_phase >= TABLE_SIZE) left_phase -= TABLE_SIZE;
        right_phase += 7;
        if( right_phase >= TABLE_SIZE) right_phase -= TABLE_SIZE;
        n_phase += 5;
        if( n_phase >= TABLE_SIZE) n_phase -= TABLE_SIZE;
      }

      return paContinue;

    }

    //When portAudio needs data, it calls this function
    static int paCallback( const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeInfo,
        PaStreamCallbackFlags statusFlags,
        void *userData )
    {
      return ((Sine*)userData)->paCallbackMethod(inputBuffer, outputBuffer,
          framesPerBuffer,
          timeInfo,
          statusFlags);
    }


    void paStreamFinishedMethod()
    {
      printf( "Stream Completed: %s\n", message );
    }

    //Called by portAudio when stream is finished
    static void paStreamFinished(void* userData)
    {
      return ((Sine*)userData)->paStreamFinishedMethod();
    }
    
    //Don't approve of this naming convention, buts it how they do it in their examples
    PaStream *stream;
    float sine[TABLE_SIZE];
    int left_phase;
    int right_phase;
    int n_phase;

    //Error Logging
    char message[20];
};

/*******************************************************************/
int main(void)
{
  Sine sine;

  // Frames_Per_Buffer doesn't matter here
  printf("PortAudio Test: output sine wave. SR = %d, BufSize = %d\n", SAMPLE_RATE, FRAMES_PER_BUFFER);

  ScopedPaHandler paInit;
  if( paInit.result() != paNoError ) goto error;

  if (sine.open(Pa_GetDefaultOutputDevice()))
  {
    if (sine.start())
    {
      printf("Play for %d seconds.\n", NUM_SECONDS );
      Pa_Sleep( NUM_SECONDS * 1000 );

      sine.stop();
    }

    sine.close();
  }

  printf("Test finished.\n");
  return paNoError;

error:
  fprintf( stderr, "An error occured while using the portaudio stream\n" );
  fprintf( stderr, "Error number: %d\n", paInit.result() );
  fprintf( stderr, "Error message: %s\n", Pa_GetErrorText( paInit.result() ) );
  return 1;
}
