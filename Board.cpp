#include <iostream>
#include "board.h"
#include <cctype>

using namespace std;



void Board::print_board() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < i; j++) {
			cout << " ";
		}
		for (char c: grid[i]) {
			cout << c << " ";
		}
		cout << "\n";
	}
}

void Board::move_neutral(int row, int col, char player) {
	// Move neutral piece to the specified spot with correct player
    grid[row][col] = toupper(player);

    //Convert char in prev pos. to lower-case
    char prevChar = grid[xpos][ypos];
    grid[xpos][ypos] = tolower(prevChar);

    //Same row, col

    xpos = row;
    ypos = col;

}

Board::Board() {
	// Default constructor
}

Board::Board(int new_size) {
    int xpos = 0;
    int ypos = 0;
	size = new_size;
	grid = vector<vector<char> >();

	for (int i = size; i > 0; i--) {
		vector<char> row;
		for (int j = 0; j < i; j++) {
			row.push_back('o');
		}
		grid.push_back(row);
	}
}
