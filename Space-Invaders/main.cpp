#include <iostream>
#include <SFML/Graphics.hpp>


class Player
{
private:
    int playerHealth = 10;
    sf::Vector2f playerPosition = sf::Vector2f(100, 100);
    int playerMovementSpeed = 6;
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

    void PlayerTakeDamage() {}
    void PlayerMove() {}
    void PlayerShootBullets() {}
};



int main()
{
    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow renderWindow(videoMode, "SFML Window");

    Player player;

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

        renderWindow.clear(sf::Color::Blue);

        renderWindow.display();
    }