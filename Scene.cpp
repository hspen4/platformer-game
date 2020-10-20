#include "Scene.h"
#include "Collectible.h"
#include "End.h"
#include "EnemyWalker.h"
#include "EnemyJumper.h"
#include "Floor.h"
#include "PhysicsObject.h"
#include "Player.h"
#include "RenderedObject.h"
#include "Score.h"
#include "Scoreboard.h"
#include <algorithm>
#include <chrono>
#include <ncurses.h>
#include <stdexcept>
#include <string>
#include <thread>
#include <unistd.h>
#include <vector>

Scene::Scene(std::string file) : player(nullptr), sb(file) {}

Scene::Scene(Scene &&other) : sb("") {
    swap(*this, other);
}

Scene& Scene::operator=(Scene &&other) {
    swap(*this, other);
    return *this;
}

void swap(Scene &a, Scene &b) {
    std::swap(a.objects, b.objects);
    std::swap(a.collision_objects, b.collision_objects);
    std::swap(a.physics_objects, b.physics_objects);
    std::swap(a.floors, b.floors);
}
Scene::~Scene() {
    for (auto obj : objects) delete obj;
    objects.clear();
    physics_objects.clear();
    collision_objects.clear();
}

template <class T>
void Scene::new_physics(char sprite, double x, double y) {
    PhysicsObject *obj = new T(sprite, x, y);
    objects.push_back(obj);
    collision_objects.push_back(obj);
    physics_objects.push_back(obj);
}

template <class T>
void Scene::new_collision(char sprite, double x, double y) {
    CollisionObject *obj = new T(sprite, x, y);
    objects.push_back(obj);
    collision_objects.push_back(obj);
}

void Scene::new_collectible(char sprite, double x, double y) {
    new_collision<Collectible>(sprite, x, y);
}
void Scene::new_end(char sprite, double x, double y) {
    new_collision<End>(sprite, x, y);
}
void Scene::new_enemy_walker(char sprite, double x, double y) {
    new_physics<EnemyWalker>(sprite, x, y);
}
void Scene::new_enemy_jumper(char sprite, double x, double y) {
    new_physics<EnemyJumper>(sprite, x, y);
}
void Scene::new_player(char sprite, double x, double y) {
    Player *obj = new Player(sprite, x, y);
    objects.push_back(obj);
    physics_objects.push_back(obj);
    // the player intentionally isn't added to CollisionObjects, because we
    // don't care if they collide with themself
    if (player) throw std::runtime_error("adding a player when one already exists");
    player = obj;
}
void Scene::new_floor(int left_x, int right_x, int y) {
    Floor *floor = new Floor(left_x, right_x, y);
    objects.push_back(floor);
    floors.push_back(floor);
}

GameState Scene::tick(std::vector<int> keys) {
    // ~60 ticks per second
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    player->set_keys(keys); // pass user input to player object
    for (auto obj : physics_objects) {
        obj->tick();
        obj->set_grounded(false);
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
    if (player) player->render();
    return player ? player->get_state() : GameState::Playing;
}

void Scene::remove_object(RenderedObject *obj) {
    objects.erase(std::remove(objects.begin(), objects.end(), obj),
                  objects.end());
    collision_objects.erase(std::remove(collision_objects.begin(),
                                        collision_objects.end(),
                                        static_cast<CollisionObject *>(obj)),
                            collision_objects.end());
    physics_objects.erase(std::remove(physics_objects.begin(),
                                      physics_objects.end(),
                                      static_cast<PhysicsObject *>(obj)),
                          physics_objects.end());
    delete obj;
}

// getters and setters

Scoreboard Scene::get_scoreboard() { return sb; }
void Scene::set_scores(std::vector<Score> lb) { sb.set_scores(lb); }
float Scene::get_score() { return player->get_score(); }
void Scene::add_score(Score score) { sb.add_score(score); }
