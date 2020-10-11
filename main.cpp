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
    //noecho();
    nodelay(stdscr, true);

    // get size of screen
    int maxY, maxX;
    getmaxyx(stdscr, maxY, maxX);

    Scene scene;

    scene.new_player('@', 1, 5);
    scene.new_floor(0, maxX, 10);

 

    while (1) {
        scene.tick();
        refresh();

    }

    endwin();

    return 0;
}
