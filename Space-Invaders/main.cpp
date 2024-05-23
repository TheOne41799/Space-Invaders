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

		//Draw a green circle
		sf::CircleShape circle(50);
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(renderWindow->getSize().x/2 - circle.getRadius(), 
						   renderWindow->getSize().y/2-circle.getRadius());
		renderWindow->draw(circle);

		//Draw a red square
		sf::RectangleShape square(sf::Vector2f(50, 50));
		square.setFillColor(sf::Color::Red);
		square.setPosition(renderWindow->getSize().x / 2 - 200, renderWindow->getSize().y / 2);
		renderWindow->draw(square);

		//Draw a blue triangle
		sf::ConvexShape triangle;
		triangle.setPointCount(3);
		triangle.setPoint(0, sf::Vector2f(200, 200));
		triangle.setPoint(1, sf::Vector2f(170, 300));
		triangle.setPoint(2, sf::Vector2f(240, 300));
		triangle.setFillColor(sf::Color::Blue);
		renderWindow->draw(triangle);


		//Draw outscal logo texture as a sprite
		sf::Texture outscalLogoTexture;
		outscalLogoTexture.loadFromFile("assets/textures/outscal_logo.png");

		sf::Sprite outscalLogoSprite;
		outscalLogoSprite.setTexture(outscalLogoTexture);

		outscalLogoSprite.setPosition(400, 100);
		outscalLogoSprite.setRotation(45);
		outscalLogoSprite.setScale(0.4, 0.4);

		renderWindow->draw(outscalLogoSprite);


		//Draw text
		sf::Font font;
		font.loadFromFile("assets/fonts/bubbleBobble.ttf");
		
		sf::Text text("SFML is awesome!", font, 50);
		text.setFillColor(sf::Color::White);
		text.setPosition(renderWindow->getSize().x / 2 - 200, 20);

		renderWindow->draw(text);



		//Draw a blue triangle - Drawing this triangle resulted in error - ????
		//sf::ConvexShape triangleB;
		//triangleB.setFillColor(sf::Color::Blue);
		//triangleB.setPoint(0, sf::Vector2f(renderWindow->getSize().x / 2 + 30, renderWindow->getSize().y / 2 + 30));
		//triangleB.setPoint(1, sf::Vector2f(renderWindow->getSize().x / 2 + 45, renderWindow->getSize().y / 2 - 15));
		//triangleB.setPoint(2, sf::Vector2f(renderWindow->getSize().x / 2 + 60, renderWindow->getSize().y / 2 + 30));
		//renderWindow->draw(triangleB);

		////Drawing a circle at the center
		//sf::CircleShape circle(50);
		//circle.setFillColor(sf::Color::Black);
		//circle.setPosition(350, 350);
		//renderWindow->draw(circle);

		////Drawing a circle each on all four corners
		//sf::CircleShape circle1(25), circle2(25), circle3(25), circle4(25);
		//circle1.setFillColor(sf::Color::Red);
		//circle2.setFillColor(sf::Color::Red);
		//circle3.setFillColor(sf::Color::Red);
		//circle4.setFillColor(sf::Color::Red);
		////By default circle1 will be drawn at top left
		//circle2.setPosition(renderWindow->getSize().x - 2 * circle2.getRadius(), 0);
		//circle3.setPosition(0,renderWindow->getSize().y - 2 * circle3.getRadius());
		//circle4.setPosition(renderWindow->getSize().x - 2 * circle2.getRadius(), 
		//					renderWindow->getSize().y - 2 * circle2.getRadius());
		//renderWindow->draw(circle1);
		//renderWindow->draw(circle2);
		//renderWindow->draw(circle3);
		//renderWindow->draw(circle4);

		////Draw a circle on top of first circle
		//sf::CircleShape circle5(50);
		//circle5.setFillColor(sf::Color::Blue);
		//circle5.setPosition(400, 400);
		//renderWindow->draw(circle5);

		//Draw a rectangle
		//sf::RectangleShape rectangle(sf::Vector2f(250, 100));
		//rectangle.setFillColor(sf::Color::Green);
		//rectangle.setPosition(100, 10);
		//renderWindow->draw(rectangle);

		//Draw a triabgle
		//sf::ConvexShape triangle;
		//triangle.setPointCount(3);
		//triangle.setPoint(0, sf::Vector2f(200, 200));
		//triangle.setPoint(1, sf::Vector2f(170, 300));
		//triangle.setPoint(2, sf::Vector2f(240, 300));
		//triangle.setFillColor(sf::Color::Yellow);
		//renderWindow->draw(triangle);

		//Draw a pentagon
		//sf::ConvexShape pentagon;
		//pentagon.setPoint(0, sf::Vector2f(600, 200));
		//pentagon.setPoint(1, sf::Vector2f(640, 240));
		//pentagon.setPoint(2, sf::Vector2f(620, 280));
		//pentagon.setPoint(3, sf::Vector2f(580, 280));
		//pentagon.setPoint(5, sf::Vector2f(560, 240));
		//pentagon.setFillColor(sf::Color::White);
		//renderWindow->draw(pentagon);

		//Draww a line
		//sf::LineShape line();

		renderWindow->display();
	}
}