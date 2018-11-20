#define cimg_display 0
#define cimg_use_jpeg

#include "/usr/local/include/CImg.h"
#include "RGBVals.hpp"
#include <vector>

typedef std::vector<RGB::RGBVals> RGBVec;

class JpegParser {

  public:
    /*
     * Constructor taking the file name
     */
    JpegParser(const char* src) : 
        src_file_(src),
        pict_vec_()
        {}// End JpegParser();

    /*
     * Fills member variable picture vector
     */
    void fill_vec(){
      cimg_library::CImg<unsigned char> cimg_src_(src_file_);
      int width_ = cimg_src_.width();
      int height_ = cimg_src_.height();
      for (int r = 0; r < height_; r++){
        for (int c = 0; c < width_; c++){
          RGB::Color r = (RGB::Color)cimg_src_(c,r,0,0);
          RGB::Color g = (RGB::Color)cimg_src_(c,r,0,1);
          RGB::Color b = (RGB::Color)cimg_src_(c,r,0,2);
          RGB::RGBVals vals(r,g,b);
          pict_vec_.push_back(vals);
        }
      }
    }// End fill_vec();
    
    /*
     * Getter for picture vector
     */
    RGBVec get_rgb_vec(){
      return pict_vec_;
    }// End get_rgb_vec();


  private:
    const char* src_file_;
    RGBVec pict_vec_;
};// End JpegParser Class
