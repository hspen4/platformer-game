#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include "Score.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <algorithm>

extern int max_x, max_y;

int menu(void) {
	noecho();
	nodelay(stdscr,false);
	// get level
	mvprintw(max_y / 2, (max_x / 2) - 10, "Choose a level (1-9)");
	int lvl;
	while ((lvl = getch()) < '0' || lvl > '9');
	lvl -= '0';
	// turn off curses options
	clear();
	nodelay(stdscr,true);

	return lvl;

}