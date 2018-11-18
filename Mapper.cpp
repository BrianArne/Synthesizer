#include <stdio>
#include <iostream>
#include <jpegparser.h>

typedef unsigned short Color;
typedef int[16] PartialCont;
typedef std::vector<RGBVals*> RGBVec;
typedef std::vector<PartialCont> Partials;
#define MAX_PARTIALS 16
#define MAX_HZ 5500
#define MIN_HZ 1500

class Mapper {

  public:
    Mapper (int f) : fund_hz_(f){}

    std::vector<Partials>*  map_partials(RGBVec color_vec, int fund){
      Partials * pix_partials = new Partials();
      for (auto pixels : color_vec){
        //for each pixel, map 16 partials
        //Pointer done right?
        int * pixel_map[16] = new PartialCont();
        for(int i = 0; i < MAX_PARTIALS; i++){
          //Holder 1
          //Algo goes here
          pixel_map[i] = 1;
        }
        Partials->push_back(pixel_map);
      }
      paritals_ = pix_partials;
      return pix_partials;
    }

    int[] min_max_freq(){
      int min_max[2];
      min_max[0] = (int)(MIN_HZ / fund_);
      min_max[1] = (int)(MAX_HZ / fund_);
      min_max_ = min_max;
      return min_max;
    }

    Partials* get_partials(){
      return partials_;
    }

  private:
    Partials * partials_;
    int fund_hz_;
    int min_max_[2];

}; 
