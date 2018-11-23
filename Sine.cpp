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
#include "Mapper.hpp"
#include "JpegParser.hpp"

#define NUM_SECONDS   (1)
#define SAMPLE_RATE   (44100)
#define FRAMES_PER_BUFFER  (64)

#ifndef M_PI
#define M_PI  (3.14159265)
#endif

extern int which_partial;

class Sine
{
  public:
    Sine(int hertz, Mapper::PartialContainer partials, int * which_partial) : stream(0),
             left_phase(0), 
             right_phase(0),
             n_phase(0),
             par0(0), par1(0), par2(0), par3(0), par4(0), par5(0),
             par6(0), par7(0), par8(0), par9(0), par10(0), par11(0), 
             par12(0), par13(0), par14(0), par15(0),
             which_partial_(which_partial),
             table_size_((int) SAMPLE_RATE / hertz),
             partials_(partials)
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
        int fake_val = partials_[*which_partial_][0]*sine[par0] +
                       partials_[*which_partial_][1]*sine[par1] +
                       partials_[*which_partial_][2]*sine[par2] +
                       partials_[*which_partial_][3]*sine[par3] +
                       partials_[*which_partial_][4]*sine[par4] +
                       partials_[*which_partial_][5]*sine[par5] +
                       partials_[*which_partial_][6]*sine[par6] +
                       partials_[*which_partial_][7]*sine[par7] +
                       partials_[*which_partial_][8]*sine[par8] +
                       partials_[*which_partial_][9]*sine[par9] +
                       partials_[*which_partial_][10]*sine[par10] +
                       partials_[*which_partial_][11]*sine[par11] +
                       partials_[*which_partial_][12]*sine[par12] +
                       partials_[*which_partial_][13]*sine[par13] +
                       partials_[*which_partial_][14]*sine[par14] +
                       partials_[*which_partial_][15]*sine[par15];
        *out++ = fake_val;
        par0 += 1; if (par0 >= table_size_) par0 -= table_size_;
        par1 += 2; if (par1 >= table_size_) par1 -= table_size_;
        par2 += 3; if (par2 >= table_size_) par2 -= table_size_;
        par3 += 4; if (par3 >= table_size_) par3 -= table_size_;
        par4 += 5; if (par4 >= table_size_) par4 -= table_size_;
        par5 += 6; if (par5 >= table_size_) par5 -= table_size_;
        par6 += 7; if (par6 >= table_size_) par6 -= table_size_;
        par7 += 8; if (par7 >= table_size_) par7 -= table_size_;
        par8 += 9; if (par8 >= table_size_) par8 -= table_size_;
        par9 += 10; if (par9 >= table_size_) par9 -= table_size_;
        par10 += 11; if (par10 >= table_size_) par10 -= table_size_;
        par11 += 12; if (par11 >= table_size_) par11 -= table_size_;
        par12 += 13; if (par12 >= table_size_) par12 -= table_size_;
        par13 += 14; if (par13 >= table_size_) par13 -= table_size_;
        par14 += 15; if (par14 >= table_size_) par14 -= table_size_;
        par15 += 16; if (par15 >= table_size_) par15 -= table_size_;
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
    int par0, par1, par2, par3, par4, par5, par6, par7, par8,
        par9, par10, par11, par12, par13, par14, par15;
    int table_size_;
    int * which_partial_;
    Mapper::PartialContainer partials_;
    //For error logging
    char message[20];
};// End Sine Class

/*******************************************************************/
int main(void)
{
  int hertz;
  std::cout << "Hertz? " << std::endl;
  std::cin >> hertz;

  JpegParser::JpegParser pic("Flowers.jpg");
  pic.fill_vec();
  JpegParser::RGBVec vec = pic.get_rgb_vec();

  Mapper::Mapper map(440, vec);
  map.map_partials();
  Mapper::PartialContainer partials = map.get_partials();
  int which_partial;

  Sine sine(hertz, partials, &which_partial);

  // Frames_Per_Buffer doesn't matter here
  printf("PortAudio Test: output sine wave. SR = %d, BufSize = %d\n", SAMPLE_RATE, FRAMES_PER_BUFFER);

  ScopedPaHandler paInit;
  if( paInit.result() != paNoError ) goto error;

  if (sine.open(Pa_GetDefaultOutputDevice()))
  {
    if (sine.start())
    {
      for (which_partial = 0; which_partial < partials.size(); which_partial++){
        printf("Play for %d seconds.\n", NUM_SECONDS );
        Pa_Sleep( NUM_SECONDS * 1000 );
      }
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
