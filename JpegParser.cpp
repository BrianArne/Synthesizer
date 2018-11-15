#define cimg_display 0
#define cimg_use_jpeg
#include "/usr/local/include/CImg.h"
#include <iostream>
#include <stdio.h>
typdedef unsigned short Color;

//MagikImage 
// /usr/local/Cellar/jpeg/9c
struct RGBVals{
  Color r_;
  Color g_;
  Color b_;

};

int main(void){

  cimg_library::CImg<unsigned char> src("Flowers.jpg");
  int width = src.width();
  int height = src.height();
  std::cout << width << "x" << height << std::endl;
  int flower_pixels = 0;
  for (int r = 0; r < height; r++){
    for (int c = 0; c < width; c++){
      int blue = (int)src(c,r,0,2);
      int red = (int)src(c,r,0,0);
      int green = (int)src(c,r,0,1);
      if( blue > 150 && red < 125 && green < 125){
        flower_pixels++;
        std::cout << "(" << r << "," << c << ") ="
          << " R" << red
          << " G" << green 
          << " B" << blue << std::endl;
      }
    }
  }
  std::cout << "Just flower pixels: " << flower_pixels << std::endl;
  std::cout << "Total Pixels: " << (width * height) << std::endl;
  std::cout << "Flower/Picture: " << (double)(flower_pixels)/(double)(width * height) << std::endl;
  std::cout << "1 second per pixel is 3,3333 hours of sound..." << std::endl;
  std::cout << "Image size: " << width << "x" << height << std::endl;
  return 0;
  }


