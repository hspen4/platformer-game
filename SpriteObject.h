#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "RenderedObject.h"

// an object that has an x and y position, and a single character sprite
// to be rendered each frame
class SpriteObject : public RenderedObject {
private:
    char sprite[2];
protected:
    int x;
    int y;
public:
    SpriteObject(char sprite, int x = 0, int y = 0);
    virtual ~SpriteObject() = default;
    virtual void render() override;
    int get_x();
    int get_y();
    void set_x(int _x);
    void set_y(int _y);
};

#endif
