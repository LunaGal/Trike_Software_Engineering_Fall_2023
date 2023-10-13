BUILDFLAGS = -Wall
OBJFLAGS = -Wall -O

main: main.o Board.o Game.o
	g++ $(BUILDFLAGS) -o $@ $^

main.o: main.cpp
	g++ $(OBJFLAGS) -o $@ -c++ $^