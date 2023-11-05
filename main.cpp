#include <iostream>
#include "game.h"
#include "board.h"

using namespace std;

int main(int argc, char const *argv[])
{
    Game game = Game();
    game.run_game();
    return 0;
}
