#ifndef SNAKE_H
#define SNAKE_H

#include "random_point.h"
#include "snake_part.h"
#include <vector>

enum direction { LEFT = 0, DOWN, RIGHT, UP, STATIC };

class Snake {
private:
  int dir;  // Direction
  Snake_part snake_part; // Position on board
  std::vector<Snake_part> body;

public:
  Snake(int width, int height);
  bool update_snake(int width, int height);
  void update_direction(char ch);
  int get_x(int i) const;
  int get_y(int i) const;
  int get_dir() const;
  //std::vector<Snake_part> get_body() const;
  unsigned long get_snake_size() const;
  void add_snake_part();
};

#endif
