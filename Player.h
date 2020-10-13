#ifndef PLAYER_H
#define PLAYER_H

#include "PhysicsObject.h"
#include <vector>

class Player : public PhysicsObject {
public:
    bool is_player = true;
    // inherit ctors
    using PhysicsObject::PhysicsObject;
    void tick() override;
    bool check_collision(Player *p) override;
    bool collide(Player *p) override;
    void set_keys(std::vector<int>); // pass user input to class
private:
    void input(); // parse user input
    std::vector <int> keys; // hold user input
};

#endif
