namespace RGB{
  typedef unsigned short Color;

  struct RGBVals{
    //Constructor
    RGBVals(Color r, Color g, Color b) : r_(r), g_(g), b_(b){}

    // Public member variables
    Color r_;
    Color g_;
    Color b_;
  };// End RGBVals();
}
