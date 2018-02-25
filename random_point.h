#ifndef RANDOM_POINT_H
#define RANDOM_POINT_H

#include <iostream>
#include <random>

// Simple function for random point generation
void get_random_point(int &x, int &y, int width, int height) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist_x(1, width);
  std::uniform_int_distribution<int> dist_y(1, height);

  x = dist_x(mt);
  y = dist_y(mt);
}

#endif
