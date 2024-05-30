#pragma once
#include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h"


namespace Main
{
	class GameService
	{
	private:
		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;

		void Initialize();
		void InitializeVariables();
		void Destroy();

	public:
		GameService();
		~GameService();

		void Ignite();
		void Update();
		void Render();
		bool IsRunning();
	};
}
