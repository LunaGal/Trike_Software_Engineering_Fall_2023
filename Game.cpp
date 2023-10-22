#include <iostream>
#include "board.h"
#include "game.h"
using namespace std;

Game::Game(int num){
	player_name = 'A';
	Board inital_board(num);

	curr_board = inital_board;
}

void Game::request_starting_pos() {

	int row, col;

	cout << "Enter where you would like to place the neutral piece" << endl;
	cout << "Enter one number for the row you would like to start on" << endl;
	cin >> row;
	
	while (row > curr_board.get_size()){
		cout << "Your input is invalid because the board only has " << curr_board.get_size() << " rows" << endl;
		cout << "Enter one number for the row you would like to start on" << endl;
		cin >> row;
	}
	
	cout << "Enter how many spaces form the left you would like to place the piece" << endl;
	cin >> col; 


	while (row < col){
		cout << "Your input is invalid because row " << row <<  " has only " << row << " spaces." << endl;
		cout << "Enter where you would like to place the neutral piece" << endl;
		cout << "Enter one numner for the row you would like to start on" << endl;
		cin >> row;
		cout << "Enter how many spaces form the left you would like to place the piece" << endl;
		cin >> col; 
	}


	row = row - 1;
	col = col - 1;

	curr_board.move_neutral(row, col, player_name);

}

void Game::display_board() {
	curr_board.print_board();
}
