#include "harness.h"
#include "../Enemy.h"
#include "../Player.h"

void enemy(Harness *assert) {
    assert->context("enemies");

    Player p('@', 0, 0);
    Enemy e('M', 0, 0);

    p.set_x(10);
    p.set_y(10);
    float original_score = p.get_score();

    // collide the enemy and player, the player should respawn and lose score
    e.collide(&p);

    assert->lt(p.get_score(), original_score, "reduced score after touching an enemy");
    assert->eq(p.get_x(), 0.0, "reset position after touching an enemy");
    assert->eq(p.get_y(), 0.0);
}
