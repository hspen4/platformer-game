# convert these to object files if compile time becomes an issue
OBJS=RenderedObject.cpp Background.cpp CollisionObject.cpp Floor.cpp Collectible.cpp Platform.cpp PhysicsObject.cpp Player.cpp Enemy.cpp

# depend on the .cpp and .h files
game: $(OBJS) $(subst .cpp,.h,$(OBJS)) main.cpp
	$(CXX) -o game $(OBJS) main.cpp

test: $(OBJS) $(subst .cpp,.h,$(OBJS)) tests/*
	# todo - write tests
	$(CXX) -o test $(OBJS) tests/test.cpp

.PHONY: clean
clean:
	$(RM) game test

