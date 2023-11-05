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
	if ((new_xpos + 1 > size)||(new_xpos < 0)) {
		//new_xpos is out of bounds
		return false;
	}

	if ((new_ypos > new_xpos)||(new_ypos < 0)) {
		//new_ypos is out of bounds
		return false;
	}

	if (grid[new_xpos][new_ypos] != 'o') {
		//check positon to be moved to
		return false;
	}


	if ((new_ypos == ypos) && (new_xpos == xpos)) {
		//new position same as previous position
		return false;
	}

	if (new_xpos == xpos) {
		//moving in a stright line in some direction 	
		return check_legal_horizontal(new_xpos, new_ypos);
	}

	else {
		return check_legal_diagonal(new_xpos, new_ypos);
	}
	//systematicaly ckeck everything in a stright line between (xpos,ypos) and (new_xpos, new_ypos)
    return false;
}

bool Board::check_legal_horizontal(int new_xpos, int new_ypos) {
	// checks if the movement is legal moving horizontally
	// Break into cases by direction


	// moving to left
	if (new_ypos < ypos) {
		for (int i = ypos - 1; i > new_ypos; i--) {
			if(grid[xpos][i] != 'o'){
				return false;
			}
		}
	}

	// moving to right 
	else {
		for (int i = ypos + 1; i < new_ypos; i++){
			if(grid[xpos][i] != 'o'){
				return false;
			}
		}
	}

	return true;
}


bool Board::check_legal_diagonal(int new_xpos, int new_ypos){
	// checks if the movement legal when moving in a diagonal direction
	// Break into cases by direction

	// We are going down
	if (new_xpos > xpos) {
		// The DR situation
		if (new_ypos > ypos) {
			// Check each position from here to destination
			int distance = (new_xpos - xpos);
			for (int i = 1; i <= distance; i++) {
				if (grid[xpos + i][ypos + i] != 'o') {
					return false;
				}
			}
		}

		// Else we are in the DL situation
		else {
			// Check each position from here to destination
			int distance = (new_xpos - xpos);
			for (int i = 1; i <= distance; i++) {
				if (grid[xpos + i][ypos] != 'o') {
					return false;
				}
			}
		}
	}

	// We are going up
	else {
		// The UL situation
		if (new_ypos < ypos) {
			// Check each position from here to destination
			int distance = (xpos - new_xpos);
			for (int i = 1; i <= distance; i++) {
				if (grid[xpos - i][ypos - i] != 'o') {
					return false;
				}
			}
		}

		// Else we are in the UR situation
		else {
			// Check each position from here to destination
			int distance = (xpos - new_xpos);
			for (int i = 1; i <= distance; i++) {
				if (grid[xpos - i][ypos] != 'o') {
					return false;
				}
			}
		}
	}

	return true;
}

bool Board::move_relative(int distance, string direction, char player) {

    // Accepts L, R, UL, UR, DL, DR and in number
    // Find coordinates and call move_neutral
    int row = xpos;
    int col = ypos;

    if (point_up) {
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
    }

    else {
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
	    else if (direction == "DL" ||  direction == "DR") {
	        row = row - distance;
	        if (direction == "DL") {
	            col = col - distance;
	        }
	    }
	    //Move down left and down right by distance
	    else if (direction == "UL" ||  direction == "UR") {
	        row = row + distance;
	        if (direction == "UR") {
	            col = col + distance;
	        }
	    }
    }

    bool valid = check_legal_movement(row, col);

    if (valid) {
    	//Call move_neutral
    	move_neutral(row, col, player);
    }

    return valid;
}

int Board::get_size(){
	return size;
}

//Define winner
char Board::get_winner() {
    int directions[6][2] = {
            //UR - {x_diff, y_diff}
            {-1,0},
            //UL
            {-1,-1},
            //L
            {0,-1},
            //R
            {0,1},
            //DL
            {1,0},
            //DR
            {1,1}
    };
    char p1Name = tolower(grid[xpos][ypos]);
    char p2Name;

    int p1Score = 1;
    int p2Score = 0;

    for (auto d : directions) {
        int test_x = xpos + d[0];
        int test_y = ypos + d[1];

        bool validPos = check_bounds(test_x, test_y);
        //Incrementing player if coordinate is valid
        if (validPos) {
            if (grid[test_x][test_y] == p1Name) {
                p1Score += 1;
            }
            else {
                p2Name = grid[test_x][test_y];
                p2Score += 1;
            }
        }
    }
    //Returning winner based on their score
    if (p1Score > p2Score) {
        return p1Name;
    }
    return p2Name;

}

bool Board::game_over() {
	int directions[6][2] = {
            //UR - {x_diff, y_diff}
            {-1,0},
            //UL
            {-1,-1},
            //L
            {0,-1},
            //R
            {0,1},
            //DL
            {1,0},
            //DR
            {1,1}
    	};

    for (auto d : directions) {
        int test_x = xpos + d[0];
        int test_y = ypos + d[1];

        bool validPos = check_bounds(test_x, test_y);
        //Incrementing player if coordinate is valid
        if (validPos) {
            if (grid[test_x][test_y] == 'o') {
               return false;
        	}
    	}
	}
	return true;	
}

bool Board::check_bounds(int test_x, int test_y) {
    if ((test_x + 1 > size)||(test_x < 0)) {
        //test_x is out of bounds
        return false;
    }

    if ((test_y > test_x)||(test_y < 0)) {
        //test_y is out of bounds
        return false;
    }
    return true;
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
