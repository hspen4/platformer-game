#include "../Scene.h"

extern int max_y, max_x;

Scene level_1() {
    Scene scene("scores/level_1.txt");

    scene.new_player('@', 1, 5);
    scene.new_collectible('!', 14, max_y - 4);
    scene.new_collectible('!', 103, max_y - 4);
    scene.new_end('*', 1, max_y - 10);

    scene.new_floor(0, max_x, max_y - 1);

    scene.new_floor(10, 21, max_y - 3);
    scene.new_floor(20, 40, max_y - 6);
    scene.new_floor(39, 50, max_y - 3);
    scene.new_floor(70, 81, max_y - 3);
    scene.new_floor(80, 100, max_y - 6);
    scene.new_floor(99, 110, max_y - 3);
    scene.new_floor(39, 81, max_y - 9);

    scene.new_enemy_walker('M', 5, max_y - 2);
    scene.new_enemy_jumper('|', 60, max_y - 10);

    return scene;
}
