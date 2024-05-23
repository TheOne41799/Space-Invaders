#include <iostream>
#include <SFML/Graphics.hpp>


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

    void PlayerTakeDamage(){}

    void PlayerMove(float offsetX)
    {
        playerPosition.x += offsetX;
    }

    void PlayerShootBullets(){}
};


int main()
{
    //sf::VideoMode videoMode = *(new sf::VideoMode(800, 600));
    //sf::RenderWindow* renderWindow = new sf::RenderWindow(videoMode, "SFML Window");
    //what is the difference between this syntax where 'new' keyword is used and the below syntax?

    //sf::VideoMode videoMode = sf::VideoMode(800, 600);
    //sf::RenderWindow renderWindow = sf::RenderWindow(videoMode, "SFML Window");
    //What is the difference between these various syntaxes?

    sf::VideoMode videoMode(800, 600);
    sf::RenderWindow renderWindow(videoMode, "SFML Window");

    Player player;
    player.playerTexture.loadFromFile("assets/textures/player_ship.png");
    player.playerSprite.setTexture(player.playerTexture);

    std::cout << player.GetPlayerScore() << std::endl;

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

    return 0;
}