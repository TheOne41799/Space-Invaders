#include "Header/Main/GameService.h"


//This is the main project


int main()
{
    using namespace Main;

    GameService* gameService = new GameService();

    gameService->Ignite();

    while (gameService->IsRunning())
    {
        gameService->Update();

        gameService->Render();
    }

    return 0;
}