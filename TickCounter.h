#ifndef TICKCOUNTER_H
#define TICKCOUNTER_H

// counter that fires every `frequency` ticks
class TickCounter {
public:
    TickCounter(int frequency);
    const int frequency;
    int count;
    // increment the counter, returning true if it fired
    bool check();
};

#endif
