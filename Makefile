#Makefile for Synthesizer

CXX = g++
CXXPALIB = /usr/local/lib/libportaudio.dylib

#Targets

all: Sine

Sine: Sine_Example.o
	$(CXX) $(CXXPALIB) -o Sine Sine_Example.o


Sine.o: Sine_Example.cpp
	$(CXX) -c Sine_Example.cpp
