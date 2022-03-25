#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#include "imageio.h"

int invert(std::string filename)
{
  std::string input = filename;
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
  std::string input = filename;
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
      if (col >= w/2) {
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

int box(std::string filename)
{
  std::string input = filename;
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
      if (row < h*3/4 && row > h/4 && col > w/4 && col < w*3/4) {
        out[row][col] = 255;
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("boxImage.pgm",out, h, w);
  return 0;
}

int frame(std::string filename)
{
  std::string input = filename;
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
      if ((row <= h*3/4 && row >= h/4 && col >= w/4 && col <= w*3/4) && (row == h*3/4 || row == h/4 || col == w/4 || col == w*3/4)) {
        out[row][col] = 255;
      }
      else {
        out[row][col] = img[row][col];
      }
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("frameImage.pgm",out, h, w);
  return 0;
}

/*int scale(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int scaledout[h*2][w*2];
  for(int row = 0; row < h; row += 2) {
    for(int col = 0; col < w; col++) {
      scaledout[row][col] = img[row][col];
      scaledout[row+1][col] = img[row][col];
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("scaleImage.pgm",scaledout, h, w);
  return 0;
}*/

int pixelate(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  int total, avg;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int out[MAX_H][MAX_W];
  for(int row = 0; row < h; row += 2) {
    for(int col = 0; col < w; col += 2) {
      total = img[row][col] + img[row+1][col] + img[row][col+1] + img[row+1][col+1];
      avg = total / 4;
      out[row][col] = avg;
      out[row+1][col] = avg;
      out[row][col+1] = avg;
      out[row+1][col+1] = avg;
    }
  }
  // and save this new image to file "outImage.pgm"
  writeImage("pixelatedimage.pgm",out, h, w);
  return 0;
}
