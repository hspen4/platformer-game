#ifndef PHYSICSOBJECT_H
#define PHYSICSOBJECT_H

#include "CollisionObject.h"
#include "TickCounter.h"

// object that has gravity
class PhysicsObject : public CollisionObject {
public:
    PhysicsObject(char sprite, float x, float y);
    // called on every game tick - should apply momentum, gravity, etc
    virtual void tick();
    void render() override;
    bool grounded();
    void set_grounded(bool);
    void set_dx(double);
    void set_dy(double);
    double get_dx();
    double get_dy();
    bool collide(Player *) override;

protected:
    // old location for cleaning
    int old_y, old_x;

private:
    // apply momentum from arrow keys
    double dy;
    double dx;
    bool on_ground;    // check if object on ground
    bool check_tick(); // returns true if we should update
};

#endif
