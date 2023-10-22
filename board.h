#ifndef TRIKE_BOARD_H
#define TRIKE_BOARD_H
#include <vector>
#include <cstring>
using namespace std;

class Board {
	private:
		int size;

        // Position of neutral piece
        int xpos;
        int ypos;
		vector<vector<char> > grid;

	public:
		void print_board();
		void move_neutral(int row, int col, char player);
		// Accepts L, R, UL, UR, DL, DR
		void move_relative(int distance, string direction, char player);
		int get_size();
		Board();
		Board(int new_size);
};
#endif