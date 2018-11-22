#include <jpegparser.h>
#include "Mapper.hpp"

#define MAX_HZ 5500
#define MIN_HZ 1500

/*
 * Constructor taking the fundamental hertz
 */
Mapper::Mapper (int f) : fund_hz_(f){
}//End Mapper();

/*
 * Maps all pixels to parital blocks
 */
void Mapper::map_partials(RGB::RGBVec color_vec, int fund){
  for (auto pixels : color_vec){
    //Implement ME
  }
}//End map_partials();

/*
 * Constructs pair of paritals numbers with range 
 * human ear is most sensitive to
 */
void Mapper::min_max_freq(){
  min_max_ = std::pair<int,int> pair((int));
  int min = (int)(MIN_HZ / fund_);
  int max = (int)(MAX_HZ / fund_);
  min_max_ = std::pair<int,int> pair(min, max);
}// End min_max_freq();

/*
 * Getter for partials_
 */
Mapper::PartialContainer Mapper::get_partials(){
  return partials_;
}//End get_partials();
