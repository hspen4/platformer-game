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

// class that holds all of the objects rendered within a level

// initialize with file so we know where to write the scoreboard to
Scene::Scene(std::string file) : player(nullptr), sb(file) {}

// implement copy constructor to pass scenes between functions
Scene::Scene(Scene &&other) : sb("") {
    std::swap(*this, other);
}

// implement assignment operator for same reason
Scene& Scene::operator=(Scene &&other) {
    std::swap(*this, other);
    return *this;
}

// erases all elements from object vectors when the scene is no longer needed
Scene::~Scene() {
    for (auto obj : objects) delete obj;
    objects.clear();
    physics_objects.clear();
    collision_objects.clear();
}

// physics objects are placed in their own vector so we can call movement behaviour each tick
template <class T>
void Scene::new_physics(char sprite, double x, double y) {
    PhysicsObject *obj = new T(sprite, x, y);
    objects.push_back(obj);
    collision_objects.push_back(obj);
    physics_objects.push_back(obj);
}

// collision objects have their own vector so we can check if they touched anything on each tick
template <class T>
void Scene::new_collision(char sprite, double x, double y) {
    CollisionObject *obj = new T(sprite, x, y);
    objects.push_back(obj);
    collision_objects.push_back(obj);
}

// functions used to create specific collision and physics objects and add them to scene
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
// floors need their own vector so we can check if the player has not only collided with them, but also if they have left them
void Scene::new_floor(int left_x, int right_x, int y) {
    Floor *floor = new Floor(left_x, right_x, y);
    objects.push_back(floor);
    floors.push_back(floor);
}

// calls the physics and other behaviour on each tick based on user input keys
GameState Scene::tick(std::vector<int> keys) {
    // ~60 ticks per second
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    player->set_keys(keys); // pass user input to player object

    // call physics
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

    // update object locations by rendering them again
    for (auto obj : objects) obj->render();
    if (player) player->render();

    // check if game is still going
    return player ? player->get_state() : GameState::Playing;
}

// allows a single object to be removed from vectors and deleted from heap
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
