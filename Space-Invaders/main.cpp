#include <iostream>
#include <SFML/Graphics.hpp>


class Player
{

};



int main()
{
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