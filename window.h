#ifndef WINDOW_H
#define WINDOW_H

#define WIDTH 50
#define HEIGHT 20

#include "snake.h"
#include <ncurses.h>
#include <thread>

static WINDOW *win;
static Snake s(WIDTH, HEIGHT);

// Creates a window of given size
void create_window(int x, int y);
// Prints snake to the window
void printw_snake();
// Clears snake from the window(screen)
void clearw_snake();
// Main game loop
void game();
// Add fruit to the game
void generate_fruit();
#endif
