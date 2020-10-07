#ifndef FLOOR_H
#define FLOOR_H

#include "RenderedObject.h"
#include "PhysicsObject.h"

class Floor : public RenderedObject {
private:
    int left_x;
    int right_x;
    int y;
public:
    Floor(int left_x, int right_x, int y);
    void collide(PhysicsObject *obj);
    void render() override;
};

#endif
