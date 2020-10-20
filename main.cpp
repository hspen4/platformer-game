#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include "Score.h"
#include "GameState.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <algorithm>

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
    scene.new_end('*', 1, max_y-10);

    scene.new_floor(0, max_x, max_y - 1);

    scene.new_floor(10, 21, max_y - 3);
    scene.new_floor(20, 40, max_y - 6);
    scene.new_floor(39, 50, max_y - 3);
    scene.new_floor(70, 81, max_y - 3);
    scene.new_floor(80, 100, max_y - 6);
    scene.new_floor(99, 110, max_y - 3);
    scene.new_floor(39, 81, max_y - 9);

    scene.new_enemy('M', 5, max_y - 2);
    GameState state = GameState::Playing;

    while (state == GameState::Playing) {
        // get keys pressed on each tick
        std::vector <int> keys;
        int key;
        while ((key = getch()) != ERR) {
            keys.push_back(key); // get non-blocking input if available
        }

        state = scene.tick(keys);
        refresh();
    }

    nodelay(stdscr,false);
    echo();
    move(1,0);
    clrtobot();
    if (state == GameState::Won) {
        mvprintw(1,0,"You win! Enter a name for the leaderboard: ");
    } else if (state == GameState::Dead) {
        mvprintw(1,0,"You died! Enter a name for the leaderboard: ");
    }
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    char name[9];
    scanw("%8s%*[^\n]",name);
    //scanw("%*[^\n]%8s%*[^\n]",name);

    // add score and name to board

    clear();
    Score playerSc(name, scene.get_score());
    scene.add_score(playerSc);

    // get the scores and sort them

    std::vector<Score> sb = scene.get_scoreboard().get_scores();
    std::sort(sb.begin(), sb.end());
    scene.set_scores(sb);

    // display the scores
    int j = 0;
    for (auto i : sb) {
        mvprintw(2 + j, (max_x / 2) - 5, i.get_name().c_str());
        mvprintw(2 + j, (max_x / 2) + 5, std::to_string(i.get_points()).c_str());
        j++;
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    getch();

    endwin();

    return 0;
}
