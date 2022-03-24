#pragma once
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>
#include "imageio.h"

int invert(std::string filename);
int invertHalf(std::string filename);
int box(std::string filename);
int frame(std::string filename);
