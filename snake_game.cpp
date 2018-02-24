#include <iostream>
#include <ncurses.h>
#include <thread>

typedef struct direction {
  int x;
  int y;
} direction;

int main() {

  initscr();
  noecho();
  int height, width, y, x;

  height = 20;
  width = 50;
  x = y = 5;
  printw("press q to exit");
  WINDOW *win = newwin(height, width, 10, 10);
  refresh();

  box(win, 0, 0);
  wrefresh(win);

  curs_set(0);

  // wmove(win, 0, 0);
  mvwaddch(win, y, x, '#');
  wrefresh(win);

  direction dir = {.x = 0, .y = 0};

  char ch;
  timeout(0);
  while ((ch = getch()) != 'q') {
    mvwaddch(win, y, x, ' ');
    switch (ch) {
    case 'w':
    case 'W':
    case '8':
      if (y > 1)
        y--;
      dir.y = -1;
      dir.x = 0;
      break;
    case '4':
    case 'a':
    case 'A':
      if (x > 1)
        x--;
      dir.x = -1;
      dir.y = 0;
      break;
    case 's':
    case 'S':
    case '5':
      if (y < 18)
        y++;
      dir.y = 1;
      dir.x = 0;
      break;
    case 'd':
    case 'D':
    case '6':
      if (x < 48)
        x++;
      dir.x = 1;
      dir.y = 0;
      break;
    case 'c':
      wclear(win);
      break;
    default:
      if (x > 1 && x < 48 && y > 1 && y < 18) {
        x += dir.x;
        y += dir.y;
      }
      break;
    }

    mvwaddch(win, y, x, '#');
    wrefresh(win);
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
  }

  int c = getch();

  endwin();

  return 0;
}
