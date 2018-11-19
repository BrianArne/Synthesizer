#Makefile for Synthesizer

CXX = g++
CXXPALIB = /usr/local/lib/libportaudio.dylib
CXXJHEAD = ./jpeg-6b/jpeglib.h

#Targets

all: Sine Flowers

Sine: Sine.o
	$(CXX) Sine.o -lportaudio -o Sine

Sine.o: Sine.cpp
	$(CXX) -c Sine.cpp 

Flowers: JpegParser.o 
	$(CXX) JpegParser.o -ljpeg -o Flowers

JpegParser.o: JpegParser.cpp
	$(CXX) -c JpegParser.cpp

