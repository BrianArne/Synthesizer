#Makefile for Synthesizer

CXX = g++ -std=c++11
CXXPALIB = /usr/local/lib/libportaudio.dylib

#Targets

all: Sine

Sine: Sine.o JpegParser.o Mapper.o
	$(CXX) Sine.o JpegParser.o Mapper.o -lportaudio -ljpeg -o Sine

Sine.o: Sine.cpp Mapper.hpp JpegParser.hpp
	$(CXX) -c Sine.cpp 

Mapper.o: Mapper.cpp Mapper.hpp JpegParser.hpp RGBVals.hpp
	$(CXX) -c Mapper.cpp

JpegParser.o: JpegParser.cpp JpegParser.hpp RGBVals.hpp
	$(CXX) -c JpegParser.cpp

