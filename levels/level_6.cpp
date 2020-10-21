#include "../Scene.h"

extern int max_y, max_x;

Scene level_6() {
    Scene scene("scores/level_6.txt");

    scene.new_player('@', 1, max_y - 2);
    scene.new_end('*', 21, max_y - 15);

    scene.new_floor(0, 5, max_y - 1);
    scene.new_floor(9, 9, max_y - 5);
    scene.new_floor(13, 13, max_y - 8);
    scene.new_floor(17, 17, max_y - 11);
    scene.new_floor(21, 21, max_y - 14);
    scene.new_floor(12, 20, max_y - 3);
    scene.new_floor(25, 25, max_y - 5);
    scene.new_floor(29, 40, max_y - 9);
    scene.new_floor(44, 56, max_y - 13);
    scene.new_floor(47, 47, max_y - 16);
    scene.new_floor(24, 44, max_y - 19);
 
    scene.new_collectible('!', 25, max_y - 6);
    scene.new_collectible('!', 13, max_y - 9);

    scene.new_enemy_jumper('|', 9, max_y - 6);
    //  scene.new_enemy_jumper('|', 13, max_y - 9);
    scene.new_enemy_jumper('|', 17, max_y - 12);
    scene.new_enemy_walker('M', 28, max_y - 20);
    scene.new_enemy_walker('M', 50, max_y - 14);
    scene.new_enemy_walker('M', 16, max_y - 4);

    return scene;
}
