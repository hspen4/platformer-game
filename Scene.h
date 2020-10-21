#ifndef SCENE_H
#define SCENE_H

#include "Floor.h"
#include "GameState.h"
#include "PhysicsObject.h"
#include "Player.h"
#include "RenderedObject.h"
#include "Score.h"
#include "Scoreboard.h"
#include <string>
#include <vector>

#include "EnemyJumper.h"

// the scene object holds all objects, and is responsible for ticking
// physics and rendering everything
class Scene {
private:
    // every object
    std::vector<RenderedObject*> objects;
    std::vector<CollisionObject*> collision_objects;
    std::vector<PhysicsObject*> physics_objects;
    std::vector<Floor*> floors;

    Player *player;
    void remove_object(RenderedObject *obj);
    Scoreboard sb;

public:
    Scene(std::string file);
    ~Scene();
    // this holds raw pointers, so copying is a Mistake
    Scene(const Scene &other) = delete;          // copy ctor
    void operator=(const Scene &other) = delete; // copy assignment
    Scene(Scene &&other);
    Scene& operator=(Scene &&other);         // move assign
    friend void swap(Scene &a, Scene &b);

    // calls the constructors for different objects and adds them to a vector in the scene
    void new_floor(int left_x, int right_x, int y);
    void new_player(char sprite, double x = 0, double y = 0);
    template <class T> void new_collision(char sprite, double x, double y);
    template <class T> void new_physics(char sprite, double x, double y);

    void new_collectible(char sprite, double x = 0, double y = 0);
    void new_end(char sprite, double x, double y);
    void new_enemy_walker(char sprite, double x = 0, double y = 0);
    void new_enemy_jumper(char sprite, double x = 0, double y = 0);

    void new_jumper(char sprite, double x, double y);

    // ticks the game
    GameState tick(std::vector<int>);

    // manipulates score and scoreboard using the player object
    Scoreboard get_scoreboard();
    float get_score();
    void add_score(Score);
    void set_scores(std::vector<Score>);

};

#endif
