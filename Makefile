# convert these to object files if compile time becomes an issue
OBJS=RenderedObject.cpp Background.cpp CollisionObject.cpp Floor.cpp Collectible.cpp Platform.cpp PhysicsObject.cpp Player.cpp Enemy.cpp

game: $(OBJS) $(subst .cpp,.h,$(OBJS)) main.cpp
	$(CXX) -o game $(OBJS) main.cpp

clean:
	$(RM) game

