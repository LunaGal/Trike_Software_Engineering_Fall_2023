#include <iostream>
#include "board.h"
#include "game.h"
using namespace std;
#ifndef SPACES
#define spaces curr_board.get_size() - row + 1
#endif

Game::Game(int num){
	player_name = 'A';
	Board inital_board(num);

	curr_board = inital_board;
}

Game::Game() {
	// Empty constructor
}

void Game::request_starting_pos() {
	
	int row, col;

	cout << "Enter where you would like to place the neutral piece" << endl;
	row = request_int("row");
	
	while (row > curr_board.get_size() || row <= 0) {
		cout << "Your input is invalid because the board has rows 1 to " << curr_board.get_size() << " rows" << endl;
		row = request_int("row");
	}

	if (row == 1){
		col = 1;
		//sets row and col to the correct index
		row = row - 1;
		col = col - 1;
		curr_board.move_neutral(row, col, player_name);
		return;
	}
	
	cout << "How many spaces form the left you would like to place the piece? (1 to " << row << ")" << endl;
	col = request_int("column"); 


	while (col > row || col <= 0){
		cout << "Your input is invalid because row " << row <<  " has 1 to " << row << " spaces." << endl;
		cout << "Enter where you would like to place the neutral piece" << endl;
		row = request_int("row");
		while (row > curr_board.get_size()|| row <= 0) {
			cout << "Your input is invalid because the board has rows 1 to" << curr_board.get_size() << " rows" << endl;
			row = request_int("row");
		}
		cout << "How many spaces form the left you would like to place the piece? (1 to " << row << ")" << endl;
		col = request_int("column"); 
	}


	row = row - 1;
	col = col - 1;

	curr_board.move_neutral(row, col, player_name);
}

void Game::display_board() {
	curr_board.print_board();
}

void Game::start_game() {
	player_name = 'A';
	int size = request_size();
	// Change this to be based on user input
	bool orientation = true;
	orientation = request_orientation();

	// True is pointing up, false is pointing down
	Board inital_board(size, orientation);
	curr_board = inital_board;
}

void Game::request_movement() {
	cout << "Please specify how you would like to move." << endl;
	cout << "Enter a direction followed by a distance." << endl;
	cout << "For direction, enter UL, UR, DL, DR, L, or R." << endl;
	cout << "For distance, enter a single whole number." << endl;

	string direction = "";
	int distance;

	// Take in input

	direction = request_direction();
	distance = request_int("distance");

	// Validate format

	// Validate move legality
	// Rule 1: Not Out of Bounds
	// Rule 2: No markers in the way
	bool valid = curr_board.move_relative(distance, direction, player_name);
	while (!valid ) {
		// re-request input
		cout << "Not a valid move." << endl;
		cout << "Please specify how you would like to move." << endl;
		direction = request_direction();
		distance = request_int("distance");
	}
}


int request_int(const string name) {
	int output;
	string input;
	bool is_int = false;

	cout << "Enter one number for " << name << endl;
	cin >> input;

	try {
		output = stoi(input);
		is_int = true;
	}

	catch (const std::invalid_argument& ia) {
		cout << "Invalid input.\n";
	}

	while (!is_int) {
		cout << "You must enter a number, not " << input << endl;
		cout << "Enter one number for " << name << endl;
		cin >> input;

		try {
			output = stoi(input);
			is_int = true;
		}

		catch (const std::invalid_argument& ia) {
			cout << "Invalid input.\n";
		}
	}

	return output;
}

string request_direction() {
	string language[] = {"UR", "UL", "DR", "DL", "R", "L"};
	string input;
	bool is_valid = false;

	cout << "Enter one value for direction." << endl;
	cin >> input;

	// Check if input is a valid direction
	for (auto s : language) {
		is_valid = (is_valid || (s == input));
	}

	while (!is_valid) {
		cout << "You must enter a valid direction, not " << input << endl;
		cout << "The valid directions are ";
		for (auto s : language) {
			cout << s << " ";
		}
		cout << endl;
		cout << "Enter one value for direction." << endl;
		cin >> input;

		// Check if input is a valid direction
		for (auto s : language) {
			is_valid = (is_valid || (s == input));
		}
	}

	return input;
}

// Returns true if user enters up, false if user enters down
// Requests new input if the input does not match up or down
bool request_orientation() {
	cout << "Please specify the starting orientation" << endl;
	cout << "Enter \"up\" for pointing up and \"down\" for pointing down: ";

	string input;
	cin >> input;

	bool valid = (input == "up" || input == "down");

	while (!valid) {
		cout << input << " is not a valid orientation" << endl;
		cout << "Only \"up\" and \"down\" are valid inputs" << endl;
		cout << "Enter \"up\" for pointing up and \"down\" for pointing down: ";
		cin >> input;
		valid = (input == "up" || input == "down");
	}

	return (input == "up");
}


// Requests an integer from 2 to 40
int request_size() {
	int size = 2;
	cout << "Please enter a starting size for the board. The size can be from 2 to 40, inclusive." << endl;
	size = request_int("size");
	// Make sure it's between 2 and 4
	while (size < 2 || size > 40) {
		if (size < 2) {
			cout << size << " is too small. Please enter a size between 2 and 40." << endl;
			size = request_int("size");
		}
		else {
			cout << size << " is too large. Please enter a size between 2 and 40." << endl;
			size = request_int("size");
		}
	}
	return size;
}


