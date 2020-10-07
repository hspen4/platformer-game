#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include "RenderedObject.h"

class SpriteObject : public RenderedObject {
private:
    char sprite;
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
