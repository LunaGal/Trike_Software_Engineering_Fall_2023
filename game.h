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
		void start_game();
		void request_movement();
		void run_game();
		bool check_over();
		Game(int num);
		Game();
};

int request_int(const string);
bool request_orientation();
int request_size();
string request_direction();
#endif

