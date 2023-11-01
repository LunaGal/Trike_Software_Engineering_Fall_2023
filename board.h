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
        bool point_up;
		vector<vector<char> > grid;

	public:
		void print_board();
		void print_debug();
		void move_neutral(int row, int col, char player);
		// Accepts L, R, UL, UR, DL, DR
		void move_relative(int distance, string direction, char player);
		int get_size();
		bool check_legal_movement(int new_xpos, int new_ypos);
		bool Board::check_legal_diagonal(int new_xpos, int new_ypos);

		Board();
		Board(int new_size);
		Board(int new_size, bool new_orientation);
};
#endif