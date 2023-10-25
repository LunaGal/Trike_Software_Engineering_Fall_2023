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

void Game::request_starting_pos() {
	// Update to take inputs for new form of indexing like: 
	/* 5 o o o o o
	   4  o o o o
	   3   o o o
	   2    o o
	   1     o
	*/
	int row, col;

	cout << "Enter where you would like to place the neutral piece" << endl;
	row = request_int("row");
	
	while (row > curr_board.get_size()) {
		cout << "Your input is invalid because the board only has " << curr_board.get_size() << " rows" << endl;
		row = request_int("row");
	}
	
	cout << "How many spaces form the left you would like to place the piece?" << endl;
	col = request_int("column"); 


	while (col > spaces){
		cout << "Your input is invalid because row " << row <<  " has only " << (spaces) << " spaces." << endl;
		cout << "Enter where you would like to place the neutral piece" << endl;
		row = request_int("row");
		while (row > curr_board.get_size()) {
			cout << "Your input is invalid because the board only has " << curr_board.get_size() << " rows" << endl;
			row = request_int("row");
		}
		cout << "How many spaces form the left you would like to place the piece?" << endl;
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
	// sets player etc
	// asks for size
	// "driver" for game
}

void Game::request_movement() {
	// asks player where to go until they specify a legal move
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
