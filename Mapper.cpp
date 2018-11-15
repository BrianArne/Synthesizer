#include <stdio>
#include <iostream>
#include <jpegparser.h>

typedef unsigned short Color;

class Mapper {

  public:
    Mapper (Color r, Color g, Color b) : red_(r), green_(g), blue_(b) {}

    std::vector<int> map_partials(std::vector<RGBVals>, int fundamental){


    }


  private:

    Color red_;
    Color _green_;
    Color _blue_;


}; 
