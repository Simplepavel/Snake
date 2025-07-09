#include "Game.h"

int main()
{
    srand(time(NULL));
    Game Snake_Game(640, 480, 16, 15);
    Snake_Game.Go();
    return 0;
}
