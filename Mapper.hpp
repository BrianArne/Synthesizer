#ifndef MAPPER_H
#define MAPPER_H

#include<utility>
#include<vector>
#include "RGBVals.hpp"
#include "JpegParser.hpp"


#define MAX_PARTIALS 16
namespace Mapper{

  typedef std::vector<std::vector<double>> PartialContainer;

  class Mapper{

    public:
      /*
       * Constructor taking the fundametal hertz
       */
      Mapper(JpegParser::RGBVec pixel_vec);

      /*
       * Initializes min and max pair
       */
      void min_max_freq();

      /*
       * Maps pixel values to 16 partials and store arr in member vector
       */
      void map_partials();

      /*
       * Getter for mapped partials
       */
      PartialContainer get_partials();

    private:

      //Minimum is the first number in the pair. Max is the second number in the pair.
      JpegParser::RGBVec pixel_vec_;
      PartialContainer partial_container_;

  };
}
#endif
