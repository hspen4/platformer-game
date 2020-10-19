#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <chrono>

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

    Scene scene("scores/level_1.txt");

    scene.new_player('@', 1, 5);
    scene.new_collectible('!', 14, max_y-4);
    scene.new_collectible('!', 103, max_y-4);
    scene.new_end('*', 50, max_y-10);

    scene.new_floor(0, max_x, max_y - 1);

    scene.new_floor(10, 21, max_y - 3);
    scene.new_floor(20, 40, max_y - 6);
    scene.new_floor(39, 50, max_y - 3);
    scene.new_floor(70, 81, max_y - 3);
    scene.new_floor(80, 100, max_y - 6);
    scene.new_floor(99, 110, max_y - 3);
    scene.new_floor(39, 81, max_y - 9);

    bool playing = true;

    while (playing) {
        // get keys pressed on each tick
        std::vector <int> keys;
        int key;
        while ((key = getch()) != ERR) {
            keys.push_back(key); // get non-blocking input if available
        }

        playing = scene.tick(keys);
        refresh();

    }

    move(1,0);
    clrtobot();
    mvprintw(1,0,"You win! Press any key to continue...");
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    while (getch() != ERR);
    nodelay(stdscr,false);
    getch();

    endwin();

    return 0;
}
