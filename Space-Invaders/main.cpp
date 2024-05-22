#include <SFML/Graphics.hpp>

int main()
{
	sf::VideoMode videoMode = *(new sf::VideoMode(800, 800));

	sf::RenderWindow* renderWindow = new sf::RenderWindow(videoMode, "SFML Game Window");

	//sf::RenderWindow* renderWindow = new sf::RenderWindow(videoMode, "Resizable Window", sf::Style::Resize);

	/*sf::RenderWindow* renderWindow = new sf::RenderWindow(sf::VideoMode::getFullscreenModes()[0],
		"Full Screen Window", sf::Style::Fullscreen);*/

	//renderWindow->setFramerateLimit(60);

	//renderWindow->setPosition(sf::Vector2i(300, 300));


	while (renderWindow->isOpen())
	{
		sf::Event event;

		while (renderWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				renderWindow->close();
			}
		}		

		renderWindow->clear(sf::Color(255,140,0));

		//renderWindow->setPosition(sf::Vector2i(300, 300));

		renderWindow->display();
	}
}