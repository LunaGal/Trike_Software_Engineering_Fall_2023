BUILDFLAGS = -Wall -std=c++14
OBJFLAGS = -Wall -c

main: main.cpp Board.cpp Game.cpp
	g++ $(BUILDFLAGS) -o $@ $^

clean:
	rm *.o