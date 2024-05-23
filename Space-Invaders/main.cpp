#include <iostream>
#include <SFML/Graphics.hpp>


class Player
{
    
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