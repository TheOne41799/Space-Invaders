#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


namespace Event
{
	class EventService
	{
	private:
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;

		bool IsGameWindowOpen();
		bool GameWindowWasClosed();
		bool HasQuitGame();

	public:
		EventService();
		~EventService();

		void Initialize();
		void Update();
		void ProcessEvents();
		bool PressedEscapeKey();
		bool IsKeyboardEvent();

		bool PressedLeftKey();
		bool PressedRightKey();

		bool PressedLeftMouseButton();
		bool PressedRightMouseButton();
	};
}
