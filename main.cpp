#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"
#include "funcs.h"

int main() {
  invert("image1.pgm");
  invertHalf("image1.pgm");
  return 0;
}
