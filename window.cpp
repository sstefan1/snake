#include "window.h"

// Global variables
// WINDOW *win;
// Snake s;

void create_window(int width, int height) {
  initscr();
  timeout(0);
  curs_set(0);
  noecho();
  win = newwin(height, width, 10, 0);
  mvprintw(0, 0, "x = %d; y = %d;", s.get_x(0), s.get_y(0));
  refresh();

  box(win, 0, 0);
  wrefresh(win);
}

void printw_snake() {
  for (int i = 0; i < s.get_body().size(); ++i) {
    mvwaddch(win, s.get_y(i), s.get_x(i), '@');
  }
}

// This will clear the head and the tail from screen since they are the only
// parts that change position
void clearw_snake() {
  int i = s.get_snake_size() - 1;
  mvwaddch(win, s.get_y(i), s.get_x(i), ' ');
}
void game() {
  char ch;
  printw_snake();
  generate_fruit();
  while ((ch = getch()) != 'q') {
    s.update_direction(ch);
    clearw_snake();
    s.update_snake(WIDTH, HEIGHT);
    printw_snake();
    wrefresh(win);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
  }

  endwin();
}

void generate_fruit() {
  int x_fruit, y_fruit;

  srand((unsigned)time(0));

  x_fruit = rand() % 49 + 1;
  y_fruit = rand() % 19 + 1;

  mvwaddch(win, y_fruit, x_fruit, '%');
}
