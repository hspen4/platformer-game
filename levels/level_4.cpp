#include "../Scene.h"

extern int max_y, max_x;

Scene level_4() {
    Scene scene("scores/level_4.txt");

    scene.new_player('@', 1, max_y - 2);
    scene.new_end('*', 47, max_y - 30);

    scene.new_floor(0, max_x, max_y - 1);

    scene.new_floor(45, 50, max_y - 5);
    scene.new_floor(38, 43, max_y - 9);
    scene.new_floor(45, 50, max_y - 13);
    scene.new_floor(38, 43, max_y - 17);
    scene.new_floor(45, 50, max_y - 21);
    scene.new_floor(38, 43, max_y - 25);
    scene.new_floor(45, 50, max_y - 29);

    scene.new_floor(25, 28, max_y - 9);
    scene.new_floor(60, 63, max_y - 13);
    scene.new_floor(25, 28, max_y - 17);
    scene.new_floor(60, 63, max_y - 21);
    scene.new_floor(25, 28, max_y - 25);

    scene.new_collectible('!', 26, max_y - 10);
    scene.new_collectible('!', 61, max_y - 14);
    scene.new_collectible('!', 26, max_y - 18);
    scene.new_collectible('!', 61, max_y - 22);
    scene.new_collectible('!', 26, max_y - 26);

    return scene;
}
