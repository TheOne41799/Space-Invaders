#pragma once
#include <SFML/Graphics.hpp>


namespace Graphics
{
	class GraphicService
	{
	private:
		const std::string gameWindowTitle = "Space Invaders";

		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;

		const int frameRate = 60;

		//const sf::Color gameWindowColor = sf::Color::Blue;
		const sf::Color gameWindowColor = sf::Color(200, 200, 0, 255);

		sf::VideoMode* videoMode;
		sf::RenderWindow* gameWindow;

		void SetVideoMode();
		void OnDestroy();

	public:
		GraphicService();
		~GraphicService();

		sf::RenderWindow* CreateGameWindow();

		void Initialize();
		void Update();
		void Render();
		bool IsGameWindowOpen();
		void SetFrameRate(int);

		sf::RenderWindow* GetGameWindow();
		sf::Color GetGameWindowColor();
	};
}
