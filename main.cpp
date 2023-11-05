#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Game test_game = Game();
    test_game.start_game();
    test_game.display_board();
    test_game.request_starting_pos();
    test_game.display_board();
    test_game.request_movement();
    test_game.display_board();
    test_game.request_movement();
    test_game.display_board();
    test_game.request_movement();
    test_game.display_board();
    test_game.request_movement();
    test_game.display_board();
    return 0;
}
