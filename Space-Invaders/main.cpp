#include <iostream>
#include <SFML/Graphics.hpp>
#include "Header/Gameplay/GameService.h"


/*
class Player
{
private:
    int playerHealth = 10;
    sf::Vector2f playerPosition = sf::Vector2f(400, 300);
    int playerMovementSpeed = 1;
    int playerScore = 0;
public:
    sf::Texture playerTexture;
    sf::Sprite playerSprite;

    int GetPlayerScore()
    {
        return playerScore;
    }

    void SetPlayerScore(int newScore)
    {
        playerScore = newScore;
    }

    sf::Vector2f GetPlayerPosition()
    {
        return playerPosition;
    }

    int GetPlayerMovementSpeed()
    {
        return playerMovementSpeed;
    }

    void PlayerMove(float offsetX)
    {
        playerPosition.x += offsetX;
    }

    void PlayerTakeDamage() {}
    void PlayerShootBullets() {}
};
*/



int main()
{
    GameService* gameService = new GameService();

    gameService->Ignite();

    while (gameService->IsRunning())
    {
        gameService->Update();

        gameService->Render();
    }


    /*
    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow renderWindow(videoMode, "SFML Window");

    Player player;
    player.playerTexture.loadFromFile("assets/textures/player_ship.png");
    player.playerSprite.setTexture(player.playerTexture);

    while (renderWindow.isOpen())
    {
        sf::Event event;

        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                renderWindow.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            player.PlayerMove(-1.0f * player.GetPlayerMovementSpeed());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            player.PlayerMove(1.0f * player.GetPlayerMovementSpeed());
        }

        renderWindow.clear(sf::Color::Blue);

        player.playerSprite.setPosition(player.GetPlayerPosition());
        renderWindow.draw(player.playerSprite);

        renderWindow.display();
    }
    */

    return 0;
}