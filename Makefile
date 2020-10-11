# convert these to object files if compile time becomes an issue
OBJS=Scene.cpp RenderedObject.cpp SpriteObject.cpp Background.cpp CollisionObject.cpp Floor.cpp Collectible.cpp Platform.cpp PhysicsObject.cpp Player.cpp Enemy.cpp

# clang doesn't support unused-but-set-variable
FLAGS=-std=c++11 -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -ggdb

INCLUDES=-lncurses

# depend on the .cpp and .h files
game: $(OBJS) $(subst .cpp,.h,$(OBJS)) main.cpp
	$(CXX) $(FLAGS) -o game $(OBJS) main.cpp $(INCLUDES)

test: $(OBJS) $(subst .cpp,.h,$(OBJS)) tests/*
	# todo - write tests
	$(CXX) $(FLAGS) -o test $(OBJS) tests/test.cpp $(INCLUDES)

.PHONY: clean
clean:
	$(RM) game test

