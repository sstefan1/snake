#ifndef SNAKE_H
#define SNAKE_H

#include "random_point.h"
#include <vector>

enum direction { LEFT = 0, DOWN, RIGHT, UP, STATIC };

typedef struct snake_part {
  int x, y;
} snake_part;

class Snake {
private:
  int dir; // Direction
  std::vector<snake_part> body;

public:
  Snake(int width, int height);
  bool update_snake(int width, int height);
  void update_direction(char ch);
  int get_x(int i) const;
  int get_y(int i) const;
  int get_dir() const;
  std::vector<snake_part> get_body() const;
  int get_snake_size() const;
  void add_snake_part();
};

#endif
