#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include <vector>

class Player : public PhysicsObject {
public:
    bool is_player = true;
    Player(char sprite, int x, int y);
    void tick() override;
    bool check_collision(Player *p) override;
    bool collide(Player *p) override;
    void set_keys(std::vector<int>); // pass user input to class
    void set_score(int);
    int get_score();
    void set_playing(bool);
    bool get_playing();
private:
    void input(); // parse user input
    std::vector <int> keys; // hold user input
    int score;
    bool playing;
};

#endif