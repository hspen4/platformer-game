#ifndef PLAYER_H
#define PLAYER_H

#include "GameState.h"
#include "PhysicsObject.h"
#include <vector>

// player class - takes input and can move, jump, etc
// can interact with collisionobjects, see CollisionObject::collide
class Player : public PhysicsObject {
public:
    bool is_player = true;
    Player(char sprite, float x, float y);
    void tick() override;
    bool check_collision(Player *p) override;
    bool collide(Player *p) override;
    void set_keys(std::vector<int>); // pass user input to class
    void set_score(float);
    float get_score();
    void set_state(GameState);
    GameState get_state();

private:
    void input();          // parse user input
    std::vector<int> keys; // hold user input
    float score;
    bool playing;
    GameState cur_state;
};

#endif
