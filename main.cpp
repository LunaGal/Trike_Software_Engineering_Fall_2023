#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main(int argc, char const *argv[])
{
	printf("Nothing yet\n");
	Board test_board = Board(3);
	test_board.print_board();

	Game test_game;
	
	test_game.request_starting_pos();


	return 0;
}