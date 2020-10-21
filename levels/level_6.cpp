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

    /*scene.new_floor(0, 10, max_y - 9);
    scene.new_floor(30, 50, max_y - 9);
    scene.new_floor(70, 90, max_y - 9);
    scene.new_floor(110, 130, max_y - 9);
    scene.new_floor(150, 160, max_y - 9);

    scene.new_floor(19, 21, max_y - 5);
    scene.new_floor(59, 61, max_y - 5);
    scene.new_floor(99, 101, max_y - 5);
    scene.new_floor(139, 141, max_y - 5);

    scene.new_collectible('!', 5, max_y - 10);
    scene.new_collectible('!', 35, max_y - 10);
    scene.new_collectible('!', 45, max_y - 10);
    scene.new_collectible('!', 75, max_y - 2);
    scene.new_collectible('!', 85, max_y - 2);
    scene.new_collectible('!', 115, max_y - 10);
    scene.new_collectible('!', 125, max_y - 10);
    scene.new_collectible('!', 155, max_y - 2);*/

    scene.new_enemy_jumper('|', 9, max_y - 6);
    //  scene.new_enemy_jumper('|', 13, max_y - 9);
    scene.new_enemy_jumper('|', 17, max_y - 12);

    return scene;
}
