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
        std::cout << std::endl << "next tick" << std::endl;
        scene.tick();
    }

    return 0;

    endwin();
}
