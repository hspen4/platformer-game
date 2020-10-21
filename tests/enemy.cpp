#include "harness.h"
#include "../Enemy.h"
#include "../EnemyWalker.h"
#include "../EnemyJumper.h"
#include "../Floor.h"
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

    assert->context("walker enemy");
    EnemyWalker w('M', 5, 6);
    // create a floor underneath the walker
    Floor f(2, 7, 6);

    // 100 ticks
    for (int i = 0; i < 60 * 100; i++) {
        w.tick();
        w.set_grounded(false);
        f.collide(&w);
    }
    assert->lt(w.get_y(), 6, "walker hasn't walked off edge");

    assert->context("jumper enemy");
    EnemyJumper j('|', 5, 6);
    bool jumped = false;
    for (int i = 0; i < 60 * 100; i++) {
        j.tick();
        j.set_grounded(false);
        f.collide(&j);

        if (j.get_y() < 4) jumped = true;
    }
    assert->eq(jumped, true, "jumper has jumped");
}
