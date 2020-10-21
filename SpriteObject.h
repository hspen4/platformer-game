#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "RenderedObject.h"

// an object that has an x and y position, and a single character sprite
// to be rendered each frame
class SpriteObject : public RenderedObject {
private:
    char sprite[2]; // one character to be rendered and null char

protected:
    // protect x and y values so we can get positions in other methods in the class hierarchy
    double x;
    double y;

public:
    SpriteObject(char sprite, double x = 0, double y = 0);
    virtual ~SpriteObject() = default;
    virtual void render() override; // we implement the render method here
    double get_x();
    double get_y();
    int get_render_x();
    int get_render_y();
    void set_x(double _x);
    void set_y(double _y);
};

#endif
