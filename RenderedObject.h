#ifndef RENDEREDOBJECT_H
#define RENDEREDOBJECT_H

class RenderedObject {
private:
    char sprite;
protected:
    int x;
    int y;
public:
    RenderedObject(char sprite, int x = 0, int y = 0);
    virtual ~RenderedObject() = default;
    virtual void render();
};

#endif
