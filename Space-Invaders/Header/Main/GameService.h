#pragma once
#include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h"


namespace Main
{
	enum class GameState
	{
		BOOT,
		SPLASH_SCREEN,
		MAIN_MENU,
		INSTRUCTIONS,
		GAMEPLAY,
		CREDITS,
	};


	class GameService
	{
	private:
		static GameState currentState;

		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;

		void Initialize();
		void InitializeVariables();

		void ShowSplashScreen();

	public:
		GameService();
		~GameService();

		void Ignite();
		void Update();
		void Render();
		bool IsRunning();

		static void SetGameState(GameState newState);
		static GameState GetGameState();
	};
}
