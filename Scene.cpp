#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"

Scene::Scene() {}
Scene::~Scene() {
    for (auto obj : objects) delete obj;
    objects.clear();
    physics_objects.clear();
}

void Scene::new_sprite(char sprite, int x, int y) {
    RenderedObject *obj = new SpriteObject(sprite, x, y);
    objects.push_back(obj);
}
void Scene::new_physics(char sprite, int x, int y) {
    PhysicsObject *obj = new PhysicsObject(sprite, x, y);
    objects.push_back(obj);
    physics_objects.push_back(obj);
}

void Scene::tick() {
    for (auto obj : physics_objects) obj->tick();
    for (auto obj : objects) obj->render();
}
