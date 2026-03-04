#include "Game.h"
#include "Menu.h"

int main()
{
    Menu menu;
    while (true)
    {
        menu.show();
        if(menu.shouldExit()){
            system ("clear");
            return 0;
        }
        Game game(menu.getDifficulty(),menu.getPlayerName());
        game.run();
        if (game.isQuitToMenu()){
            continue;
        }
    }
}