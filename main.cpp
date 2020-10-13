#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>

int main (void) {
    // set up curses options
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    // get size of screen
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

    Scene scene;

    scene.new_player('@', 1, 5);
    scene.new_collision('!', 2, 9);
    scene.new_floor(0, maxX, maxY - 1);
    scene.new_floor(10, 21, maxY - 3);
    scene.new_floor(20, 40, maxY - 6);
    scene.new_floor(39, 50, maxY - 3);
    scene.new_floor(70, 81, maxY - 3);
    scene.new_floor(80, 100, maxY - 6);
    scene.new_floor(99, 110, maxY - 3);
    scene.new_floor(39, 81, maxY - 9);

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
