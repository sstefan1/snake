#include "include/window.h"

int main(){
  create_window(WIDTH, HEIGHT);
  printw_snake();
  game();

  clear();
  mvprintw(20, 25, "YOU LOST. . .");
  timeout(-1);
  getch();
  clear();
  endwin();

  return 0;
}
