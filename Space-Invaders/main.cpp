#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Main/GameService.h"


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