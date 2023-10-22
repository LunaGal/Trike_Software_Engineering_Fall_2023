#ifndef TRIKE_BOARD_H
#define TRIKE_BOARD_H
#include <vector>
using namespace std;

class Board {
	private:
		int size;

        // Position of neutral piece
        int xpos = 0;
        int ypos = 0;
		vector<vector<char> > grid;

	public:
		void print_board();
		void move_neutral(int row, int col, char player);
		int get_size();
		Board();
		Board(int new_size);
};
#endif