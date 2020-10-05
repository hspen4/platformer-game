#include "Scene.h"
#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <iostream>
#include <vector>
#include <cstdlib>

int main (void) {
    Scene scene;
    // create 3 objects with random position
    for (auto c : {'!', '#', '@'}) {
        scene.new_physics(c, rand() % 5, rand() % 5);
    }

    for (int i = 0; i < 5; i++) {
        std::cout << std::endl << "next tick" << std::endl;
        scene.tick();
    }

    return 0;
}
