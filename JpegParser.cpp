#define cimg_display 0
#define cimg_use_jpeg
#include "/usr/local/include/CImg.h"
#include <iostream>
#include <stdio.h>
typedef unsigned short Color;

struct RGBVals{
  RGBVals(Color r, Color g, Color, B) : r_(r), g_(g), b_(b){}

  Color r_;
  Color g_;
  Color b_;
};

typedef std::vector<RGBVals*> RBGVec;

class JpegParser {

  public:

    JpegParser(int w=0, int h=0, std::string src=null, RGBVec pict_rgb=null) : 
        width_(w), 
        height_(h), 
        src_file_(src),
        pict_rgb_(){}

    void init_file(){
      if(src == null){
        std::cout << "No Src File" << std::endl;
        return;
      }else{
        cimg_library::CImg<unsigned char> src(src);
        width_ = src.width();
        height = src.height();
      }
    }

    void fill_vec(){
      for (int r = 0; r < height; r++){
        for (int c = 0; c < width; c++){
          Color r = (Color)src(c,r,0,0);
          Color g = (Color)src(c,r,0,1);
          Color b = (Color)src(c,r,0,2);
          RGBVals * vals = new RGBVals(r, g, b);
          pict_rgb_.push_back(vals);
        }
      }
    }

    RGBVec get_rgb_vec(){
      return pict_rgb_;
    }


  private:
    int width_;
    int height_;
    std::string src_file_;
    RGBVec pict_rgb_;
};

