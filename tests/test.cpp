#include <iostream>

#include "physics.cpp"
#include "floors.cpp"
#include "collisions.cpp"

using namespace std;

int max_y = 1000, max_x = 1000;

int main() {
    cout << "running physics tests..." << endl;
    physics();
    cout << "running floors tests..." << endl;
    floors();
    cout << "running collisions tests..." << endl;
    collisions();

    cout << "all tests passed" << endl;
    return 0;
}
