#ifndef FLOOR_H
#define FLOOR_H

#include "PhysicsObject.h"
#include "RenderedObject.h"

// a static platform that PhyisicsObjects won't fall through
// falling behaviour implemented mostly in ::collide
class Floor : public RenderedObject {
private:
    // left and right sides, inclusive
    int left_x;
    int right_x;
    int y;

public:
    Floor(int left_x, int right_x, int y); // more than one character long, unlike sprites
    void collide(PhysicsObject *obj);
    void render() override;
};

#endif
