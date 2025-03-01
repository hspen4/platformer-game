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

// displays the menu to choose a level

int menu(int levels_count) {
	noecho();
	nodelay(stdscr,false);
	clear();
	// get level
	mvprintw(0,0,"Backspace to Exit");
	mvprintw(max_y / 2, (max_x / 2) - 10, "Choose a level (1-%d)", levels_count);
	int lvl;
	// check for valid level choice or exit
	while ((lvl = getch()) < '0' || lvl > ('0' + levels_count)) {
		if (lvl == KEY_BACKSPACE) {
			// done with game
			return lvl;
		}
	}
	// get integer value of level
	lvl -= '0';
	// turn off curses options
	clear();
	nodelay(stdscr,true);

	return lvl;

}
