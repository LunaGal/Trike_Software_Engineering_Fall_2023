BUILDFLAGS = -Wall
OBJFLAGS = -Wall -c

main: main.o Board.o Game.o
	g++ $(BUILDFLAGS) -o $@ $^

main.o: main.cpp game.h board.h
	g++ $(OBJFLAGS) main.cpp -o $@

Board.o: Board.cpp board.h
	g++ $(OBJFLAGS) Board.cpp -o $@

Game.o: Game.cpp game.h board.h
	g++ $(OBJFLAGS) Game.cpp -o $@

clean:
	rm *.o