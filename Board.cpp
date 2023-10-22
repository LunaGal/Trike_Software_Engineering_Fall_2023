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
    if (xpos >= 0) {
    	char prevChar = grid[xpos][ypos];
    	grid[xpos][ypos] = tolower(prevChar);
    }

    xpos = row;
    ypos = col;

}

void Board::move_relative(int distance, string direction, char player) {
    // Accepts L, R, UL, UR, DL, DR and in number
    // Find coordinates and call move_neutral
    int row = xpos;
    int col = ypos;
    //Move diagonally
    //Move left by distance
    if (direction == "L") {
        col = col - distance;
    }
    //Move right by distance
    else if (direction == "R") {
        col = col + distance;
    }
    //Move up left o by distance
    else if (direction == "UL" ||  direction == "UR") {
        row = row - distance;
        if (direction == "UR") {
            col = col + distance;
        }
    }
    //Move down left and down right by distance
    else if (direction == "DL" ||  direction == "DR") {
        row = row + distance;
        if (direction == "DL") {
            col = col - distance;
        }
    }
    //Call move_neutral
    move_neutral(row, col, player);
}

int Board::get_size(){
	return size;
}

Board::Board() {
	// Default constructor
}

Board::Board(int new_size) {
    xpos = -1;
    ypos = -1;
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
