#pragma once
#include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h"


namespace Main
{
	enum class GameState
	{
		BOOT,
		MAIN_MENU,
		GAMEPLAY
	};


	class GameService
	{
	private:
		static GameState currentState;

		Global::ServiceLocator* serviceLocator;
		sf::RenderWindow* gameWindow;

		void Initialize();
		void InitializeVariables();
		void Destroy();

		void ShowMainMenu();

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
