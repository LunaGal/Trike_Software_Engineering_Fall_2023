#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Board test_board(5);
    test_board.print_board();
    Game test_game(3);

    test_game.display_board();
    test_game.request_starting_pos();
    test_game.display_board();
    
    return 0;
}
