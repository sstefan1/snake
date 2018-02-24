#include "snake.h"

Snake::Snake() {
  int x_head, y_head;
  srand((unsigned)time(0));

  x_head = (rand() % 49) + 1;
  y_head = (rand() % 19) + 1;
  // x_head = (rand() % 49) + 1;

  snake_part head = {.x = x_head, .y = y_head};

  body.push_back(head);
}

void Snake::update_direction(char ch) {

  switch (ch) {
  case 'w':
    dir = UP;
    break;
  case 's':
    dir = DOWN;
    break;
  case 'a':
    dir = LEFT;
    break;
  case 'd':
    dir = RIGHT;
    break;
  default:
    break;
  }
}

void Snake::update_snake(int width, int height) {
  switch (dir) {
  case UP:
    if (body[0].y > 1) {
      body[0].x += 0;
      body[0].y += -1;
    }
    break;
  case DOWN:
    if (body[0].y < height - 2) {
      body[0].x += 0;
      body[0].y += 1;
    }
    break;
  case LEFT:
    if (body[0].x > 1) {
      body[0].x += -1;
      body[0].y += 0;
    }
    break;
  case RIGHT:
    if (body[0].x < width - 2) {
      body[0].x += 1;
      body[0].y += 0;
    }
    break;
  default:
    break;
  }

  //  for (int i = 1; i < body.size() - 1;)
  //    body[i] = body[++i];
}

int Snake::get_x(int i) const { return body[i].x; }

int Snake::get_y(int i) const { return body[i].y; }

int Snake::get_dir() const { return dir; }

int Snake::get_snake_size() const { return body.size(); }

std::vector<snake_part> Snake::get_body() const { return body; }
