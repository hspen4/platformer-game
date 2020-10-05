#ifndef SCENE_H
#define SCENE_H

#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <vector>

/**
 * the scene object holds all objects, and is responsible for ticking
 * physics and rendering everything
 */
class Scene {
private:
    // every object
    std::vector<RenderedObject*> objects;
    std::vector<PhysicsObject*> physics_objects;
public:
    Scene();
    ~Scene();
    // this holds raw pointers, so copying is a Mistake
    Scene(const Scene &other) = delete; // copy ctor
    void operator=(const Scene &other) = delete; // copy assignment

    void new_rendered(char sprite, int x = 0, int y = 0);
    void new_physics(char sprite, int x = 0, int y = 0);
    void tick();
};

#endif
