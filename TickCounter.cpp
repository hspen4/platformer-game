#include "TickCounter.h"

// allows us to effectively have different tick lengths for different physics behaviours

TickCounter::TickCounter(int frequency) : frequency(frequency), count(0) {}
// check if chosen count has been reached
bool TickCounter::check() {
    count++;
    if (count >= frequency) {
        count = 0;
        return true;
    }
    return false;
}
