#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "RenderedObject.h"

// an object that has an x and y position, and a single character sprite
// to be rendered each frame
class SpriteObject : public RenderedObject {
private:
    char sprite[2];
protected:
    float x;
    float y;
public:
    SpriteObject(char sprite, float x = 0, float y = 0);
    virtual ~SpriteObject() = default;
    virtual void render() override;
    float get_x();
    float get_y();
    int get_render_x();
    int get_render_y();
    void set_x(float _x);
    void set_y(float _y);
};

#endif
