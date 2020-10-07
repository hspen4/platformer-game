#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>

int main (void) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();

    int maxY, maxX;

    getmaxyx(stdscr, maxY, maxX);

    Scene scene;

    scene.new_physics('@', 1, 5);
    scene.new_floor(0, 5, 0);

    for (int i = 0; i < 5; i++) {
        printw("next tick");
        int x, y;
        getyx(stdscr, y, x);
        move(y - 1, x);
        scene.tick();
        getch();
    }

    endwin();

    return 0;
}
