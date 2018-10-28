#include <stdio.h>
#include <math.h>
#include "portaudio.h"

#define SAMPLE_RATE (44100)
#define FRAMES_PER_BUFFER (62)

#ifndef M_PI
#define M_PI (3.14159265)
#endif

#define TABLE_SIZE (200)


class Sine
{
  public:
    Sine() : stream(0), left_phase(0), right_phase(0) 

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

