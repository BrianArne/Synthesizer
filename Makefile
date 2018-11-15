#Makefile for Synthesizer

CXX = g++
CXXPALIB = /usr/local/lib/libportaudio.dylib
CXXJHEAD = ./jpeg-6b/jpeglib.h

#Targets

all: Sine Flowers

Sine: Sine_Example.o
	$(CXX) Sine_Example.o -lportaudio -o Sine

Sine_Example.o: Sine_Example.cpp
	$(CXX) -c Sine_Example.cpp 

Flowers: JpegParser.o 
	$(CXX) JpegParser.o -ljpeg -o Flowers

JpegParser.o: JpegParser.cpp
	$(CXX) -c JpegParser.cpp

