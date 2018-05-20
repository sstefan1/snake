#ifndef SNAKE_PART_H
#define SNAKE_PART_H

// Snake_part class is added in order to comply to the rule of three and avoid
// some runtime errors when running in OS X

class Snake_part {
public:
  int x, y;

  Snake_part();
  Snake_part(int x, int y);
  Snake_part(const Snake_part &snake_part);

  Snake_part &operator=(const Snake_part &part);

  ~Snake_part();
};

#endif
