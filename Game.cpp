#include <iostream>
#include "board.h"
#include "game.h"


Game::Game(){
	player_name = 'A';
}

void Game::request_starting_pos() {

	int row, col;

	cout << "Enter where you would like to place the neutral piece" << endl;
	cout << "Enter one numner for the row you would like to start on" << endl;
	cin >> row;
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