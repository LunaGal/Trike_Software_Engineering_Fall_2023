class Board {
	private:
		int size;
		char *grid[];

	public:
		void print_board();
		void move_neutral(int row, int col, char player);
		Board();
		Board(int new_size);
};