#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>


namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED
	};


	class EventService
	{
	private:
		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;

		bool IsGameWindowOpen();
		bool GameWindowWasClosed();
		bool HasQuitGame();

		ButtonState leftMouseButtonState;
		ButtonState rightMouseButtonState;
		ButtonState leftArrowButtonState;
		ButtonState rightArrowButtonState;
		ButtonState A_ButtonState;
		ButtonState D_ButtonState;

		void UpdateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);
		void UpdateKeyboardButtonState(ButtonState& currentButtonState, sf::Keyboard::Key keyboardButton);

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

		bool PressedAKey();
		bool PressedDKey();
	};
}
