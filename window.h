#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <thread>
#include <ctime>
#include "snake.h"

#define WIDTH 50
#define HEIGHT 20

static WINDOW *win;
static Snake s;

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