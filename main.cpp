#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main(int argc, char const *argv[])
{
	Board test_board(7);
	test_board.move_neutral(0, 0, 'A');
	test_board.print_board();
	test_board.move_relative(2, "DL", 'B');
	test_board.print_board();
	test_board.move_relative(1, "UR", 'A');
	test_board.print_board();
	test_board.move_relative(3, "DR", 'B');
	test_board.print_board();
	test_board.move_relative(2, "UL", 'A');
	test_board.print_board();

    return 0;
}
