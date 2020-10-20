#include <iostream>

#include "physics.cpp"
#include "floors.cpp"
#include "collisions.cpp"

using namespace std;

int max_y = 1000, max_x = 1000;

int main() {
    Harness h;

    physics(&h);
    floors(&h);
    collisions(&h);

    h.results();
    return 0;
}
