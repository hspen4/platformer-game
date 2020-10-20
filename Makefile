OBJS=Scene.o TickCounter.o RenderedObject.o SpriteObject.o Background.o CollisionObject.o Floor.o Collectible.o Platform.o PhysicsObject.o Player.o Enemy.o EnemyWalker.o EnemyJumper.o End.o Scoreboard.o Score.o
# .objs/whatever.o
OBJSPATHS=$(addprefix .objs/,$(OBJS))

FUNCS=main.cpp menu.cpp

# every .cpp file in levels dir
LEVELS=$(wildcard levels/*)
# .objs/levels/level_whatever.o
LEVELSOBJS=$(addprefix .objs/,$(subst .cpp,.o,$(LEVELS)))

# clang doesn't support unused-but-set-variable
FLAGS=-std=c++11 -Wall -Wno-unused-but-set-variable -Wno-unknown-warning-option -ggdb

INCLUDES=-lncurses

all: game test
	./test

game: $(OBJSPATHS) $(FUNCS) $(LEVELSOBJS)
	$(CXX) $(FLAGS) -o game $(OBJSPATHS) $(FUNCS) $(LEVELSOBJS) $(INCLUDES)

test: $(OBJSPATHS) tests/*
	$(CXX) $(FLAGS) -o test $(OBJSPATHS) tests/test.cpp $(INCLUDES)

# build object files into their own directory
.objs/%.o: %.cpp
	$(CXX) $(FLAGS) -c -o $@ $<

.PHONY: clean
clean:
	$(RM) game test .objs/*.o .objs/levels/*.o scores/*.txt

