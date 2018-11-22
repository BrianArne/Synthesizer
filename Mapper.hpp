#ifndef MAPPER_H
#define MAPPER_H

#include<utility>
#include<vector>


#define MAX_PARTIALS 16
namespace Mapper{

  typedef int[MAX_PARTIALS] PartialContainer;


  class Mapper{

    public:
      /*
       * Constructor taking the fundametal hertz
       */
      Mapper(int f);

      /*
       * Initializes min and max pair
       */
      void min_max_freq();

    private:

      int fund_hz_;

      //Minimum is the first number in the pair. Max is the second number in the pair.
      std::pair<int, int> min_max_;
      std::vector<PartialContainer> partial_containter_;

  };
}
#endif
