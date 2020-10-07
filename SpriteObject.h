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
};

#endif
