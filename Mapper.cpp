#include "JpegParser.hpp"
#include <iostream>
#include "Mapper.hpp"
#include "RGBVals.hpp"

#define MAX_BRIGHTNESS 765.

/*
 * Constructor taking the fundamental hertz
 */
Mapper::Mapper::Mapper (int f, JpegParser::RGBVec pixel_vec) : 
                fund_hz_(f),
                pixel_vec_(pixel_vec)
                {}//End Mapper();

/*
 * Maps all pixels to parital blocks
 */
void Mapper::Mapper::map_partials(){
  auto it = pixel_vec_.begin();
  int total_maps = pixel_vec_.size() / 16;
  for (int i = 0; i < total_maps; i++){
    std::vector<double> holder;
    for (int j = 0; j < MAX_PARTIALS; j++){
      RGB::RGBVals pix = *it;
      double brightness = pix.r_ + pix.b_ + pix.g_;
      double overall_brightness = (brightness/MAX_BRIGHTNESS);
      holder.push_back(overall_brightness);
      it++;
    }
    partial_container_.push_back(holder);
  } 
}//End map_partials();

/*
 * Constructs pair of paritals numbers with range 
 * human ear is most sensitive to
 */
void Mapper::Mapper::min_max_freq(){
}// End min_max_freq();

/*
 * Getter for partials_
 */
Mapper::PartialContainer Mapper::Mapper::get_partials(){
  return partial_container_;
}//End get_partials();

int main(){
  JpegParser::JpegParser pic("Flowers.jpg");
  pic.fill_vec();
  JpegParser::RGBVec vec = pic.get_rgb_vec();

  Mapper::Mapper map(440, vec);
  map.map_partials();
  Mapper::PartialContainer partials = map.get_partials();
  std::cout << partials.size() << std::endl;
  for(auto arr : partials){
    for(int i = 0; i < MAX_PARTIALS; i++){
      std::cout << arr[i] << std::endl;
    }
    std::cout << "BLOCK: " << std::endl;
  }
  return 0;
}


