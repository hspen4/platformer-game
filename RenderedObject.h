#ifndef RENDEREDOBJECT_H
#define RENDEREDOBJECT_H

// root object class, and interface for rendering
class RenderedObject {
public:
    virtual void render() = 0;
    virtual ~RenderedObject() = default;
};

#endif
