#include "../include/snake.h"

Snake::Snake(int width, int height) {
  int x_head, y_head;
  get_random_point(x_head, y_head, width, height);
  Snake_part head(x_head, y_head);
  body.push_back(head);
  dir = STATIC;
}

// Movement logic
void Snake::update_direction(char ch) {
  int new_dir = dir;

  switch (ch) {
  case 'w':
    new_dir = UP;
    break;
  case 's':
    new_dir = DOWN;
    break;
  case 'a':
    new_dir = LEFT;
    break;
  case 'd':
    new_dir = RIGHT;
    break;
  default:
    break;
  }

  if (body.size() == 1)
    dir = new_dir;
  else if (abs(dir - new_dir) % 2 == 1)
    dir = new_dir;
}

bool Snake::update_snake(int width, int height) {
  int x = body[0].x;
  int y = body[0].y;

  // Check for wall collision
  if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
    return false;
  // Move body parts
  for (int i = body.size(); i > 0; --i)
    body[i] = body[i - 1];

  switch (dir) {
  case UP:
    if (body[0].y > 0) {
      body[0].x += 0;
      body[0].y += -1;
    }
    break;
  case DOWN:
    if (body[0].y < height - 1) {
      body[0].x += 0;
      body[0].y += 1;
    }
    break;
  case LEFT:
    if (body[0].x > 0) {
      body[0].x += -2;
      body[0].y += 0;
    }
    break;
  case RIGHT:
    if (body[0].x < width - 2) {
      body[0].x += 2;
      body[0].y += 0;
    }
    break;
  default:
    break;
  }
  return true;
}

int Snake::get_x(int i) const { return body[i].x; }

int Snake::get_y(int i) const { return body[i].y; }

int Snake::get_dir() const { return dir; }

unsigned long Snake::get_snake_size() const { return body.size(); }

// Causing a runtime runtime error in OS X
// std::vector<Snake_part> Snake::get_body() const { return body; }

void Snake::add_snake_part() {
  Snake_part new_part;
  body.push_back(new_part);
}
