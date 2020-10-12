#ifndef SCENE_H
#define SCENE_H

#include "RenderedObject.h"
#include "PhysicsObject.h"
#include "Floor.h"
#include "Player.h"
#include <vector>

/**
 * the scene object holds all objects, and is responsible for ticking
 * physics and rendering everything
 */
class Scene {
private:
    // every object
    std::vector<RenderedObject*> objects;
    std::vector<CollisionObject*> collision_objects;
    std::vector<PhysicsObject*> physics_objects;
    std::vector<Floor*> floors;

    Player *player;
    void remove_object(RenderedObject *obj);
public:
    Scene();
    ~Scene();
    // this holds raw pointers, so copying is a Mistake
    Scene(const Scene &other) = delete; // copy ctor
    void operator=(const Scene &other) = delete; // copy assignment

    void new_sprite(char sprite, int x = 0, int y = 0);
    void new_collision(char sprite, int x = 0, int y = 0);
    void new_physics(char sprite, int x = 0, int y = 0);
    void new_floor(int left_x, int right_x, int y);
    void new_player(char sprite, int x = 0, int y = 0);
    void tick();
};

#endif
