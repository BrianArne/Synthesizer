#include "portaudio.h"

#include <iostream>
#include <math.h>
#include <stdio.h>

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (62)
//Number of seconds should be determined by usr input

#ifndef M_PI
#define M_PI (3.14159)
#endif

#define TABLE_SIZE (200)


class Sine
{
  public:
    Sine() : stream(0), left_phase(0), right_phase(0) {
      /* initialise sinusoidal wavetable */
      for( int i=0; i<TABLE_SIZE; i++ )
      {
        sine[i] = (float) sin( ((double)i/(double)TABLE_SIZE) * M_PI * 2. );
      }
    }

  private:
    int paCallback(const void *inputBuffer, void *outputBuffer,
        unsigned long framesPerBuffer,
        const PaStreamCallbackTimeInfo* timeinfo,
        PaStreamCallbackFlags statusFlags,
        void *userData){
    //Implement this method

    }

    //Instance Variables
    PaStream *stream;
    float sine[TABLE_SIZE];
    int left_phase;
    int right_phase;
    char message[20];


};

