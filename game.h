#ifndef TRIKE_GAME_H
#define TRIKE_GAME_H
#include "board.h"
class Game {
	private:
		char player_name;
		Board curr_board;

	public:
		void request_starting_pos();
		void display_board();
		Game(int num);
};
#endif

