OBJS=Scene.o TickCounter.o RenderedObject.o SpriteObject.o Background.o CollisionObject.o Floor.o Collectible.o Platform.o PhysicsObject.o Player.o Enemy.o End.o
# .objs/whatever.o
OBJSPATHS=$(addprefix .objs/,$(OBJS))

# clang doesn't support unused-but-set-variable
FLAGS=-std=c++11 -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -ggdb

INCLUDES=-lncurses

all: game test
	./test

game: $(OBJSPATHS) main.cpp
	$(CXX) $(FLAGS) -o game $(OBJSPATHS) main.cpp $(INCLUDES)

test: $(OBJSPATHS) tests/*
	$(CXX) $(FLAGS) -o test $(OBJSPATHS) tests/test.cpp $(INCLUDES)

# build object files into their own directory
.objs/%.o: %.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) game test .objs/*.o

