BUILDFLAGS = -Wall
OBJFLAGS = -Wall -O

main: main.o Board.o Game.o
	g++ $(BUILDFLAGS) -o $@ $^

main.o: main.cpp game.h
	g++ $(OBJFLAGS) -o $@ main.cpp

Board.o: Board.cpp game.h
	g++ $(OBJFLAGS) -o $@ Board.cpp

Game.o: Game.cpp game.h
	g++ $(OBJFLAGS) -o $@ Game.cpp

clean:
	rm *.o