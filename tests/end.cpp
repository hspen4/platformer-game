#include "harness.h"
#include "../End.h"
#include "../Player.h"
#include "../GameState.h"
#include <string>

// converts a GameState to a string representing it
// needed so that we can print it
std::string val(GameState s) {
    switch (s) {
    case GameState::Playing: return "playing";
    case GameState::Won:     return "won";
    case GameState::Dead:    return "dead";
    default:                 return "unknown";
    }
}

void end(Harness *assert) {
    assert->context("end");

    Player p('@', 0, 0);
    End e('*', 0, 0);

    assert->eq(val(p.get_state()), val(GameState::Playing), "before touching end");

    // have the player touch the End object
    e.collide(&p);
    assert->eq(val(p.get_state()), val(GameState::Won), "after touching end");
}
