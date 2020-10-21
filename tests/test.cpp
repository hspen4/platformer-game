#include <iostream>

#include "physics.cpp"
#include "floors.cpp"
#include "collisions.cpp"
#include "tick_counter.cpp"
#include "end.cpp"
#include "enemy.cpp"

using namespace std;

int max_y = 1000, max_x = 1000;

int main() {
    Harness h;

    physics(&h);
    floors(&h);
    collisions(&h);
    tick_counter(&h);
    end(&h);
    enemy(&h);

    h.results();
    return 0;
}
