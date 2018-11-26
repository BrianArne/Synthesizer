// This class initializes PortAudio before use of the PortAudio API is avail.

#ifndef SCOPED_H
#define SCOPED_H
#include <portaudio.h>

class ScopedPaHandler
{
  public:
    ScopedPaHandler()
      : _result(Pa_Initialize())
    {
    }
    ~ScopedPaHandler()
    {
      if (_result == paNoError)
      {
        Pa_Terminate();
      }
    }

    PaError result() const { return _result; }

  private:
    PaError _result;
};

#endif
