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
  std::string newfilename = "inverted" + filename;
  writeImage(newfilename,out, h, w);
  std::cout << "Successfully created " << newfilename << " from " << filename << std::endl;
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
  std::string newfilename = "halfinverted" + filename;
  writeImage(newfilename,out, h, w);
  std::cout << "Successfully created " << newfilename << " from " << filename << std::endl;
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
  std::string newfilename = "box" + filename;
  writeImage(newfilename,out, h, w);
  std::cout << "Successfully created " << newfilename << " from " << filename << std::endl;
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
  std::string newfilename = "frame" + filename;
  writeImage(newfilename,out, h, w);
  std::cout << "Successfully created " << newfilename << " from " << filename << std::endl;
  return 0;
}

int scale(std::string filename)
{
  std::string input = filename;
  int img[MAX_H][MAX_W];
  int h, w;
  int j, k;
  readImage(input, img, h, w); // read it from the file "inImage.pgm"
  // h and w were passed by reference and
  // now contain the dimensions of the picture
  // and the 2-dimesional array img contains the image data
  // Now we can manipulate the image the way we like
  // for example we copy its contents into a new array
  int scaledout[h*2][w*2];
  j = 0;
  k = 0;
  for(int row = 0; row < h; row++) {
    for(int col = 0; col < w; col++) {
      scaledout[j][k] = img[row][col];
      scaledout[j+1][k] = img[row][col];
      scaledout[j][k+1] = img[row][col];
      scaledout[j+1][k+1] = img[row][col];
      k += 2;
    }
    j += 2;
    k = 0;
  }
  std::ofstream ostr;
  ostr.open("scaledimage.pgm");
  if (ostr.fail()) {
    std::cout << "Unable to write file\n";
    exit(1);
  };
  ostr << "P2" << std::endl;
  ostr << w*2 << ' ';
  ostr << h*2 << std::endl;
  ostr << 255 << std::endl;
  for (int row = 0; row < h*2; row++) {
    for (int col = 0; col < w*2; col++) {
      assert(scaledout[row][col] < 256);
      assert(scaledout[row][col] >= 0);
      ostr << scaledout[row][col] << ' ';
      ostr << std::endl;
    }
  }
  ostr.close();
  std::string newfilename = "scaled" + filename;
  std::cout << "Successfully created " << newfilename << " from " << filename << std::endl;
  return 0;
}

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
  std::string newfilename = "pixelated" + filename;
  writeImage(newfilename,out, h, w);
  std::cout << "Successfully created " << newfilename << " from " << filename << std::endl;
  return 0;
}
