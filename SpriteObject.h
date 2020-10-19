#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "RenderedObject.h"

// an object that has an x and y position, and a single character sprite
// to be rendered each frame
class SpriteObject : public RenderedObject {
private:
    char sprite[2];
protected:
    double x;
    double y;
public:
    SpriteObject(char sprite, double x = 0, double y = 0);
    virtual ~SpriteObject() = default;
    virtual void render() override;
    double get_x();
    double get_y();
    int get_render_x();
    int get_render_y();
    void set_x(double _x);
    void set_y(double _y);
};

#endif
