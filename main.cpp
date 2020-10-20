#include "GameState.h"
#include "PhysicsObject.h"
#include "RenderedObject.h"
#include "Scene.h"
#include "Score.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include <vector>

int max_y, max_x;
int menu();
Scene *level_1();
Scene *level_2();
Scene *level_3();
/*Scene *level_4();
Scene *level_5();
Scene *level_6();
Scene *level_7();
Scene *level_8();
Scene *level_9();*/

int main(void) {
    // set up curses options
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, true);
    curs_set(0);

    // get size of screen
    getmaxyx(stdscr, max_y, max_x);

    // array of levels

    Scene *(*levels[3])(void) = { &level_1,
        &level_2, &level_3,/* &level_4, &level_5
        , &level_6, &level_7, &level_8, &level_9*/
    };

    // choose level
    int lvl = menu();

    // load level
    Scene *scene = levels[lvl - 1]();

    GameState state = GameState::Playing;

    while (state == GameState::Playing) {
        // get keys pressed on each tick
        std::vector<int> keys;
        int key;
        while ((key = getch()) != ERR) {
            keys.push_back(key); // get non-blocking input if available
        }

        state = scene->tick(keys);
        refresh();
    }

    nodelay(stdscr, false);
    echo();
    move(1, 0);
    clrtobot();
    if (state == GameState::Won) {
        mvprintw(1, 0, "You win! Enter a name for the leaderboard: ");
    } else if (state == GameState::Dead) {
        mvprintw(1, 0, "You died! Enter a name for the leaderboard: ");
    }
    refresh();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    char name[9];
    scanw("%8s%*[^\n]", name);
    // scanw("%*[^\n]%8s%*[^\n]",name);

    // add score and name to board

    clear();
    Score playerSc(name, scene->get_score());
    scene->add_score(playerSc);

    // get the scores and sort them

    std::vector<Score> sb = scene->get_scoreboard().get_scores();
    std::sort(sb.begin(), sb.end());
    std::reverse(sb.begin(), sb.end());
    scene->set_scores(sb);

    // display the scores
    int j = 0;
    mvprintw(1, (max_x/2) - 5, "Name");
    mvprintw(1, (max_x/2) + 5, "Score");
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
