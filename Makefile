#Makefile for Synthesizer

CXX = g++ -std=c++11
CXXPALIB = /usr/local/lib/libportaudio.dylib

#Targets

all: Sine Mapper

Sine: Sine.o
	$(CXX) Sine.o -lportaudio -o Sine

Sine.o: Sine.cpp
	$(CXX) -c Sine.cpp 

Mapper: Mapper.o JpegParser.o
	$(CXX) Mapper.o -ljpeg JpegParser.o -o Map

Mapper.o: Mapper.cpp Mapper.hpp JpegParser.hpp RGBVals.hpp
	$(CXX) -c Mapper.cpp

#Flowers: JpegParser.o
	#$(CXX) JpegParser.o -ljpeg -o Flowers

JpegParser.o: JpegParser.cpp JpegParser.hpp RGBVals.hpp
	$(CXX) -c JpegParser.cpp

