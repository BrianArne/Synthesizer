/* @file paex_sine.c
   @ingroup examples_src
   @brief Play a sine wave for several seconds.
   @author Ross Bencina <rossb@audiomulch.com>
   @author Phil Burk <philburk@softsynth.com>
   */
/*
 * $Id: paex_sine.c 1752 2011-09-08 03:21:55Z philburk $
 *
 * This program uses the PortAudio Portable Audio Library.
 * For more information see: http://www.portaudio.com/
 * Copyright (c) 1999-2000 Ross Bencina and Phil Burk
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR
 * ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
 * CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
/*
 * The text above constitutes the entire PortAudio license; however,
 * the PortAudio community also makes the following non-binding requests:
 *
 * Any person wishing to distribute modifications to the Software is
 * requested to send the modifications to the original developer so that
 * they can be incorporated into the canonical version. It is also
 * requested that these non-binding requests be included along with the
 * license above.
 */


#include <stdio.h>
#include <math.h>
#include <portaudio.h>
#include <iostream>
#include <vector>
#include "ScopedPaHandler.hpp"

#define NUM_SECONDS   (5)
#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER  (64)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

class Sine
{
  public:
    Sine(int hertz) : stream(0),
             left_phase(0), 
             right_phase(0),
             n_phase(0),
             table_size_((int) SAMPLE_RATE / hertz)
  {
    /* Init. wavetable */
    for( int i=0; i<table_size_; i++ )
    {
      sine.push_back((float) sin( ((double)i/(double)table_size_) * M_PI * 2. ));
    }
  }// End Sine();
    
    /*
     * Opens stream on requested audio device
     */
    bool open(PaDeviceIndex index)
    {
      PaStreamParameters outputParameters;

      outputParameters.device = index;
      if (outputParameters.device == paNoDevice){
        return false;
      }

      const PaDeviceInfo* pInfo = Pa_GetDeviceInfo(index);
      if (pInfo != 0){
        printf("Output device name: '%s'\r", pInfo->name);
      }

      outputParameters.channelCount = 1;
      outputParameters.sampleFormat = paFloat32;
      outputParameters.suggestedLatency = Pa_GetDeviceInfo( outputParameters.device )->defaultLowOutputLatency;
      outputParameters.hostApiSpecificStreamInfo = NULL;

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

      if (err != paNoError){
        //Failed to open
        return false;
      }

      err = Pa_SetStreamFinishedCallback( stream, &Sine::paStreamFinished );

      if (err != paNoError){
        Pa_CloseStream( stream );
        stream = 0;

        return false;
      }

      return true;
    }// End open();

    /*
     * Closes stream
     */
    bool close()
    {
      if (stream == 0)
        return false;

      PaError err = Pa_CloseStream( stream );
      stream = 0;

      return (err == paNoError);
    }// End close();

    /*
     * Starts stream
     */
    bool start()
    {
      if (stream == 0)
        return false;

      PaError err = Pa_StartStream( stream );

      return (err == paNoError);
    }// End start();

    /*
     * Stops stream
     */
    bool stop()
    {
      if (stream == 0)
        return false;

      PaError err = Pa_StopStream( stream );

      return (err == paNoError);
    }// End stop();

  private:
    /*
     * Method that generates data for buffer when portAudio needs data
     * Scoped with Sine member vars
     */
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

      for( i=0; i<framesPerBuffer; i++ ){
        *out++ = 2*sine[left_phase] + 5*sine[right_phase];// + .2 * sine[n_phase];
        left_phase += 1;
        if (left_phase >= table_size_) left_phase -= table_size_;
        right_phase += 7;
        if( right_phase >= table_size_) right_phase -= table_size_;
        n_phase += 5;
        if( n_phase >= table_size_) n_phase -= table_size_;
      }

      return paContinue;

    }// End paCallbackMethod();

    /*
     * Method portAudio engine calls when it needs data. Passed to paCallbackMethod()
     */
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
    }// End paCallback();


    /*
     * Acknowledges to console stream finished
     */
    void paStreamFinishedMethod()
    {
      printf( "Stream Completed: %s\n", message );
    }// End paStreamFinishedMethod();

    /*
     * Static acknowledgement to console stream finished
     */
    static void paStreamFinished(void* userData)
    {
      return ((Sine*)userData)->paStreamFinishedMethod();
    }// End paStreamFinished();
   
   /*
    * Member Variables
    */ 
    PaStream *stream;
    std::vector<float> sine;
    int left_phase;
    int right_phase;
    int n_phase;
    int table_size_;
    //For error logging
    char message[20];
};// End Sine Class

/*******************************************************************/
int main(void)
{
  int hertz;
  std::cout << "Hertz? " << std::endl;
  std::cin >> hertz;

  Sine sine(hertz);

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
