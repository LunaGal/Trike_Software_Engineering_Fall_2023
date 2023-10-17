#ifndef TRIKE_BOARD_H
#define TRIKE_BOARD_H
#include <vector>

class Board {
	private:
		int size;
		std::vector<std::vector<char>> grid;

	public:
		void print_board();
		void move_neutral(int row, int col, char player);
		Board();
		Board(int new_size);
};
#endif