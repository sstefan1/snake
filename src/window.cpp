#include "include/window.h"

void create_window(int width, int height) {
  initscr();
  timeout(0);
  curs_set(0);
  noecho();
  win = newwin(height, width, 10, 0);
  mvprintw(0, 0, "x = %d; y = %d;", s.get_x(0), s.get_y(0));
  refresh();

  //  box(win, 0, 0);
  wborder(win, 0, 0, 0, 0, '+', '+', '+', '+');
  wrefresh(win);
}

void printw_snake() {
  // Not using Snake::get_body() any more due to a runtime error found when
  // running in OS X
  for (int i = 0; i < s.get_snake_size(); ++i) {
    mvwaddch(win, s.get_y(i), s.get_x(i), ACS_DIAMOND);
  }
}

// This will clear the head and the tail from the screen since they are the only
// parts that change position
void clearw_snake() {
  for (int i = 0; i < s.get_snake_size(); ++i)
    mvwaddch(win, s.get_y(i), s.get_x(i), ' ');
}
void game() {
  char ch;
  generate_fruit();

  while ((ch = getch()) != 'q') {
    s.update_direction(ch);
    clearw_snake();

    // Always be aware of head position
    int x_head = s.get_x(0);
    int y_head = s.get_y(0);

    if (x_head == x_fruit && y_head == y_fruit) {
      s.add_snake_part();
      get_random_point(x_fruit, y_fruit, WIDTH - 1, HEIGHT - 1);
      mvwaddch(win, y_fruit, x_fruit, '#');
    }

    if (!s.update_snake(WIDTH, HEIGHT))
      break;

    printw_snake();

    wrefresh(win);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
  }

  endwin();
}

void generate_fruit() {
  //  int x_fruit, y_fruit;

  get_random_point(x_fruit, y_fruit, WIDTH - 1, HEIGHT - 1);

  mvwaddch(win, y_fruit, x_fruit, '#');
}
