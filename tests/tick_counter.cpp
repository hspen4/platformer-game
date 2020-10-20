
#include "harness.h"
#include "../TickCounter.h"

void tick_counter(Harness *assert) {
    assert->context("TickCounter");

    TickCounter count_2(2);

    assert->eq(count_2.check(), false, "first tick");
    assert->eq(count_2.check(), true, "second tick");
    assert->eq(count_2.check(), false, "third tick");
    assert->eq(count_2.check(), true, "forth tick");
}
