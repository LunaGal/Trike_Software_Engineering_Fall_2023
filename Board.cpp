#include <iostream>
#include "board.h"

using namespace std;



void Board::print_board() {
	for (auto e : grid) {
		for (char f: e) {
			cout << f << " ";
		}
		cout << "\n";
	}
}
void Board::move_neutral(int row, int col, char player) {
	// Move neutral piece to the specified spot with correct player
}

Board::Board() {
	// Default constructor
}

Board::Board(int new_size) {
	size = new_size;
	grid = vector<vector<char>>();

	for (int i = size; i > 0; i--) {
		vector<char> row;
		for (int j = 0; j < i; j++) {
			row.push_back('o');
		}
		grid.push_back(row);
	}
}
