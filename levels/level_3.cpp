#include "../Scene.h"
#include "../Score.h"
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <ncurses.h>
#include <thread>
#include <unistd.h>
#include <vector>

extern int max_y, max_x;

Scene *level_3() {
    Scene *scene = new Scene("scores/level_3.txt");

    scene->new_player('@', 1, max_y - 2);


    scene->new_end('*', 80, max_y - 24);

    scene->new_floor(0, max_x, max_y - 1);

    scene->new_floor(10, 15, max_y - 4);

    scene->new_floor(15, 30, max_y - 7);
    scene->new_floor(40, 55, max_y - 7);
    scene->new_floor(65, 80, max_y - 7);

    scene->new_floor(85, 90, max_y - 11);

    scene->new_floor(15, 30, max_y - 15);
    scene->new_floor(40, 55, max_y - 15);
    scene->new_floor(65, 80, max_y - 15);

    scene->new_floor(5, 10, max_y - 19);

    scene->new_floor(15, 30, max_y - 23);
    scene->new_floor(40, 55, max_y - 23);
    scene->new_floor(65, 80, max_y - 23);

    scene->new_collectible('!', 35, max_y - 11);
    scene->new_collectible('!', 60, max_y - 11);

    scene->new_collectible('!', 35, max_y - 19);
    scene->new_collectible('!', 60, max_y - 19);

    scene->new_collectible('!', 35, max_y - 27);
    scene->new_collectible('!', 60, max_y - 27);

    scene->new_enemy_walker('M', 45, max_y - 8);
    scene->new_enemy_walker('M', 45, max_y - 16);
    scene->new_enemy_walker('M', 45, max_y - 24);



    return scene;
}
