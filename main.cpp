#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main(int argc, char const *argv[])
{
	printf("Nothing yet\n");
	Board test_board = Board(3);

	test_board.print_board();

    test_board.move_neutral(0, 1, 'A');
    test_board.print_board();
    test_board.move_neutral(1, 1, 'B');
    test_board.print_board();
    test_board.move_neutral(2, 0, 'A');
    test_board.print_board();

	Game test_game;
	return 0;
}