#include "../include/random_point.h"

// Simple function for random point generation
void get_random_point(int &x, int &y, int width, int height) {
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_int_distribution<int> dist_x(1, width - 1);
  std::uniform_int_distribution<int> dist_y(1, height - 1);

  do {
    x = dist_x(mt);
  } while (x % 2 != 0);
  y = dist_y(mt);
}

