#pragma once
#include <SFML/Graphics.hpp>


namespace Graphics
{
	class GraphicService
	{
	private:
		const int frameRate = 60;

		const std::string gameWindowTitle = "Space Invaders";

		const int gameWindowWidth = 1920;
		const int gameWindowHeight = 1080;

		const sf::Color gameWindowColor = sf::Color::Blue;

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
		void SetFrameRate(int frameRateToSet);

		sf::RenderWindow* GetGameWindow();
	};
}
