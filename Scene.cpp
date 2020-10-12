#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include "Floor.h"
#include "Player.h"
#include <stdexcept>
#include <algorithm>
#include <unistd.h>
#include <ncurses.h>
#include <vector>

Scene::Scene() : player(nullptr) {}
Scene::~Scene() {
    for (auto obj : objects) delete obj;
    objects.clear();
    physics_objects.clear();
}

void Scene::new_sprite(char sprite, int x, int y) {
    RenderedObject *obj = new SpriteObject(sprite, x, y);
    objects.push_back(obj);
}
void Scene::new_collision(char sprite, int x, int y) {
   CollisionObject *obj = new CollisionObject(sprite, x, y);
   objects.push_back(obj);
   collision_objects.push_back(obj);
}
void Scene::new_physics(char sprite, int x, int y) {
    PhysicsObject *obj = new PhysicsObject(sprite, x, y);
    objects.push_back(obj);
    collision_objects.push_back(obj);
    physics_objects.push_back(obj);
}
void Scene::new_player(char sprite, int x, int y) {
    Player *obj = new Player(sprite, x, y);
    objects.push_back(obj);
    physics_objects.push_back(obj);
    // the player intentionally isn't added to CollisionObjects, because we don't care if they collide with themself
    if (player) throw std::runtime_error("adding a player when one already exists");
    player = obj;
}
void Scene::new_floor(int left_x, int right_x, int y) {
   Floor *floor = new Floor(left_x, right_x, y);
   objects.push_back(floor);
   floors.push_back(floor);
}

void Scene::tick(std::vector <int> keys) {
   usleep(3000);
   player->setKeys(keys); // pass user input to player object
   for (auto obj : physics_objects) {
      obj->tick();
      for (auto floor : floors) {
         floor->collide(obj);
      }
   }

   // check collisions
   if (player) {
      std::vector<RenderedObject*> to_remove;
      for (auto obj : collision_objects) {
         if (obj->check_collision(player)) {
            bool should_remove = obj->collide(player);
            if (should_remove) to_remove.push_back(obj);
         }
      }
      for (auto obj : to_remove) remove_object(obj);
   }

   for (auto obj : objects) obj->render();
}

void Scene::remove_object(RenderedObject *obj) {
   objects.erase(std::remove(objects.begin(), objects.end(), obj), objects.end());
   collision_objects.erase(std::remove(collision_objects.begin(), collision_objects.end(), static_cast<CollisionObject*>(obj)), collision_objects.end());
   physics_objects.erase(std::remove(physics_objects.begin(), physics_objects.end(), static_cast<PhysicsObject*>(obj)), physics_objects.end());
   delete obj;
}


