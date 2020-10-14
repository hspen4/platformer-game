#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "CollisionObject.h"
#include "TickCounter.h"

// object that has gravity
class PhysicsObject : public CollisionObject {
public:
    PhysicsObject(char sprite, int x = 0, int y = 0);
    // called on every game tick - should apply momentum, gravity, etc
    virtual void tick();
    void render() override;
    bool grounded();
    void set_grounded(bool);
    int get_momentum_y();
    void set_momentum_y(int);
    int get_momentum_x();
    void set_momentum_x(int);
    bool collide(Player *) override;
    TickCounter x_tick;
    TickCounter y_tick;
protected:
    // old location for cleaning
    int old_y, old_x;
private:
    // apply momentum from arrow keys
    int momentum_y;
    int momentum_x;
    bool on_ground; // check if object on ground
    bool check_tick(); // returns true if we should update
};

#endif
