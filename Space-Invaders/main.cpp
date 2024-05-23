#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


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

    void PlayerTakeDamage(){}
    void PlayerMove(){}
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

        renderWindow.clear(sf::Color::Blue);

        renderWindow.display();
    }

    return 0;
}