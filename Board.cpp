#include <iostream>
#include "board.h"
#include <cctype>

using namespace std;



void Board::print_board() {
	if (point_up) {
		for (int i = 0; i < size; i++) {
			cout << (i+1);
			if ((i+1) < 10) {
				cout << " ";
			}
			for (int j = size; j > i; j--) {
				cout << " ";
			}
			for (char c: grid[i]) {
				cout << c << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	else {
		for (int i = size-1; i > -1; i--) {
			cout << (i+1);
			if ((i+1) < 10) {
				cout << " ";
			}
			for (int j = size; j > i; j--) {
				cout << " ";
			}
			for (char c: grid[i]) {
				cout << c << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}

}

void Board::print_debug() {
	cout << " ";
	for (int i = 0; i < size; i++) {
		cout << " " << (i+1);
	}
	cout << "\n";
	for (int i = 0; i < size; i++) {
		cout << (i+1) << " ";
		for (char c: grid[i]) {
			cout << c << " ";
		}
		cout << "\n";
	}
	cout << "\n";
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

bool Board::check_legal_movement(int new_xpos, int new_ypos) {
	// checks if you can go to new_xpos, new_ypos on the board
	// returns true if you can
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
        if (direction == "UL") {
            col = col - distance;
        }
    }
    //Move down left and down right by distance
    else if (direction == "DL" ||  direction == "DR") {
        row = row + distance;
        if (direction == "DR") {
            col = col + distance;
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
	point_up = true;
    xpos = -1;
    ypos = -1;
	size = new_size;
	grid = vector<vector<char> >();

	for (int i = 1; i < size + 1; i++) {
		vector<char> row;
		for (int j = 0; j < i; j++) {
			row.push_back('o');
		}
		grid.push_back(row);
	}
}

Board::Board(int new_size, bool new_orientation) {
	point_up = new_orientation;
    xpos = -1;
    ypos = -1;
	size = new_size;
	grid = vector<vector<char> >();

	for (int i = 1; i < size + 1; i++) {
		vector<char> row;
		for (int j = 0; j < i; j++) {
			row.push_back('o');
		}
		grid.push_back(row);
	}
}
