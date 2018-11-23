#ifndef JPEG_PARSER_H
#define JPEG_PARSER_H

#include "RGBVals.hpp"
#include <vector>

namespace JpegParser{

  typedef std::vector<RGB::RGBVals> RGBVec;

  class JpegParser{

    public:
      /*
       * Constructor taking the file name
       */
      JpegParser(const char* src);

      /*
       * Fills member variable picture vector
       */
      void fill_vec();

      /*
       * Getter for pict_vec_
       */
      RGBVec get_rgb_vec();

    private:
      //File being read
      const char* src_file_;
      //Vector of RGBVal pixels
      RGBVec pict_vec_;

  };// End JpegParser Class;
}
#endif
