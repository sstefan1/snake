#include "snake_part.h"

Snake_part::Snake_part(){ x = 0; y = 0;}

Snake_part::Snake_part(int x, int y) : x(x), y(y) {}

Snake_part::Snake_part(const Snake_part &snake_part) {
  x = snake_part.x;
  y = snake_part.y;
}

Snake_part::~Snake_part(){}

Snake_part &Snake_part::operator=(const Snake_part &part) {
  x = part.x;
  y = part.y;
  return *this;
}
