#define DEBUG_MSG(msg) (std::cout << msg << std::endl);

#include <iostream>
#include "../include/Game.h"

int main(int argc, char** argv)
{
    Game* game = new Game();
    game->initialize("Lab 0", 0, 0, 1366, 768, SDL_WINDOW_INPUT_FOCUS);

    DEBUG_MSG("Game object created")
    DEBUG_MSG("Game loop starting...")

    while(game->isRunning())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    DEBUG_MSG("Calling clean-up")
    game->cleanUp();

    return 0;
}