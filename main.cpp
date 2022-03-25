#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include "funcs.h"

int main() {
  std::cout << "Running Lab Tasks on 'image1':" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "invert('image1.pgm')" << std::endl;
  invert("image1.pgm");
  std::cout << std::endl;
  std::cout << "invertHalf('image1.pgm')" << std::endl;
  invertHalf("image1.pgm");
  std::cout << std::endl;
  std::cout << "box('image1.pgm')" << std::endl;
  box("image1.pgm");
  std::cout << std::endl;
  std::cout << "frame('image1.pgm')" << std::endl;
  frame("image1.pgm");
  std::cout << std::endl;
  std::cout << "scale('image1.pgm')" << std::endl;
  scale("image1.pgm");
  std::cout << std::endl;
  std::cout << "pixelate('image1.pgm')" << std::endl;
  pixelate("image1.pgm");
  std::cout << std::endl;
  std::cout << "Running Lab Tasks on 'image2':" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
  std::cout << "invert('image2.pgm')" << std::endl;
  invert("image2.pgm");
  std::cout << std::endl;
  std::cout << "invertHalf('image2.pgm')" << std::endl;
  invertHalf("image2.pgm");
  std::cout << std::endl;
  std::cout << "box('image2.pgm')" << std::endl;
  box("image2.pgm");
  std::cout << std::endl;
  std::cout << "frame('image2.pgm')" << std::endl;
  frame("image2.pgm");
  std::cout << std::endl;
  std::cout << "scale('image2.pgm')" << std::endl;
  scale("image2.pgm");
  std::cout << std::endl;
  std::cout << "pixelate('image2.pgm')" << std::endl;
  pixelate("image2.pgm");
  std::cout << std::endl;
  std::cout << std::endl;
  return 0;
}
