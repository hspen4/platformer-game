#include "../Scene.h"

extern int max_y, max_x;

Scene level_2() {
    Scene scene("scores/level_2.txt");

    scene.new_player('@', 1, 5);
    scene.new_collectible('!', 100, max_y - 24);
    scene.new_collectible('!', 150, max_y - 2);
    scene.new_collectible('!', 85, max_y - 20);
    scene.new_collectible('!', 70, max_y - 16);
    scene.new_end('*', 95, max_y - 24);

    scene.new_floor(0, max_x, max_y - 1);

    scene.new_floor(10, 30, max_y - 3);
    scene.new_floor(31, 50, max_y - 7);
    scene.new_floor(51, 65, max_y - 11);
    scene.new_floor(66, 80, max_y - 15);
    scene.new_floor(81, 90, max_y - 19);
    scene.new_floor(91, 100, max_y - 23);


    scene.new_enemy_walker('M', 100, max_y - 2);
    scene.new_enemy_walker('M', 50, max_y - 2);
    scene.new_enemy_walker('M', 45, max_y - 8);
    scene.new_enemy_walker('M', 85, max_y - 20);

    return scene;
}
