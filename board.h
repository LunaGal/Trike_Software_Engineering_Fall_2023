class Board {
	int size;
	char grid[size][size];

	void print_board();
	void move_neutral(int row, int col, char player);
};