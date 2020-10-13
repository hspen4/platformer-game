#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>

int max_y, max_x;

int main (void) {
    // set up curses options
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    // get size of screen
    getmaxyx(stdscr, max_y, max_x);

    Scene scene;

    scene.new_player('@', 1, 5);
    scene.new_collision('!', 2, 9);
    scene.new_floor(0, max_x, max_y - 1);

    while (1) {
        // get keys pressed on each tick
        std::vector <int> keys;
        int key;
        while ((key = getch()) != ERR) {
            keys.push_back(key); // get non-blocking input if available
        }

        scene.tick(keys);
        refresh();

    }

    endwin();

    return 0;
}
