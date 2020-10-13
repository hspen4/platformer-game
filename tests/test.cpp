#include <iostream>

#include "physics.cpp"

using namespace std;

int max_y = 1000, max_x = 1000;

int main() {
    cout << "running physics tests..." << endl;
    physics();

    cout << "all tests passed" << endl;
    return 0;
}
