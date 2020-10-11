#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include "Floor.h"
#include "Player.h"
#include <unistd.h>
#include <ncurses.h>

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
void Scene::new_player(char sprite, int x, int y) {
    PhysicsObject *obj = new Player(sprite, x, y);
    objects.push_back(obj);
    physics_objects.push_back(obj);
}
void Scene::new_floor(int left_x, int right_x, int y) {
   Floor *floor = new Floor(left_x, right_x, y);
   objects.push_back(floor);
   floors.push_back(floor);
}

void Scene::tick() {
    for (auto obj : physics_objects) {
        usleep(30000);
        obj->tick();
        for (auto floor : floors) {
            floor->collide(obj);
        }
    }
    for (auto obj : objects) obj->render();
}
