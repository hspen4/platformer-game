#include "TickCounter.h"

TickCounter::TickCounter(int frequency) : frequency(frequency), count(0) {}
bool TickCounter::check() {
    count++;
    if (count >= frequency) {
        count = 0;
        return true;
    }
    return false;
}
