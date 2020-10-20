#ifndef SCENE_H
#define SCENE_H

#include "RenderedObject.h"
#include "PhysicsObject.h"
#include "Floor.h"
#include "Player.h"
#include "Scoreboard.h"
#include "Score.h"
#include "GameState.h"
#include <vector>
#include <string>

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
    Scene(const Scene &other) = delete; // copy ctor
    void operator=(const Scene &other) = delete; // copy assignment

    void new_sprite(char sprite, float x = 0, float y = 0);
    void new_collectible(char sprite, float x = 0, float y = 0);
    void new_end(char sprite, float x = 0, float y = 0);
    void new_physics(char sprite, float x = 0, float y = 0);
    void new_enemy(char sprite, float x = 0, float y = 0);
    void new_floor(int left_x, int right_x, int y);
    void new_player(char sprite, float x = 0, float y = 0);
    GameState tick(std::vector <int>);
    Scoreboard get_scoreboard();
    int get_score();
    void add_score(Score);
    void set_scores(std::vector <Score>);
};

#endif
