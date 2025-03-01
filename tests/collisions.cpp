#include "harness.h"
#include "../Player.h"
#include "../CollisionObject.h"

// CollisionObject is abstract, so we need to subclass it for this test
class TestCollisionObject : public CollisionObject {
public:
    bool has_collided = false;
    // inherit ctors
    using CollisionObject::CollisionObject;
    // handle a collision
    virtual bool collide(Player *p) {
        has_collided = true;
        return true;
    };
};

void collisions(Harness *assert) {
    assert->context("collisions");
    Player p('@', 0, 0);
    TestCollisionObject c('!', 5, 5);

    assert->eq(c.check_collision(&p), false, "not touching");

    p.set_x(5);
    p.set_y(5);
    assert->eq(c.check_collision(&p), true, "touching");

    assert->eq(c.has_collided, false, "before calling collision cb");
    c.collide(&p);
    assert->eq(c.has_collided, true, "after calling collision cb");
}
