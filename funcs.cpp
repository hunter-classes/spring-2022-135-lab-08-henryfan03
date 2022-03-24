#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#include "imageio.h"

int invert(std::string filename)
{
  std::string input = "image1.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      //std::cout << row << " " << col << img[row] << img[col] << std::endl;
      //out[row][col] = img[255-row][255-col];
      out[row][col] = 255-img[row][col];
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("invertedImage.pgm",out, h, w);
  return 0;
}

int invertHalf(std::string filename)
{
  std::string input = "image1.pgm";
  int img[MAX_H][MAX_W];
  int h, w;
  int halfmark = h/2;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      if (row > halfmark) {
        out[row][col] = 255-img[row][col];
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("halfInvertedImage.pgm",out, h, w);
  return 0;
}
