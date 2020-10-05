#include "RenderedObject.h"
#include "PhysicsObject.h"
#include <iostream>
#include <vector>
#include <cstdlib>

int main (void) {
    std::vector<PhysicsObject*> physics;
    std::vector<RenderedObject*> renders;

    // create 3 objects with random position
    for (auto c : {'!', '#', '@'}) {
        auto obj = new PhysicsObject(c, rand() % 5, rand() % 5);
        renders.push_back(obj);
        physics.push_back(obj);
    }

    for (int i = 0; i < 5; i++) {
        std::cout << std::endl << "next tick" << std::endl;
        for (auto obj : physics) obj->tick();
        for (auto obj : renders) obj->render();
    }

    // cleanup
    for (auto obj : renders) delete obj;
    renders.clear();
    physics.clear();

    return 0;
}
