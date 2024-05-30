#include "../../Header/Event/EventService.h"
#include "../../Header/Gameplay/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"


EventService::EventService()
{
	gameWindow = nullptr;
}

EventService::~EventService() = default;


void EventService::Initialize()
{
	gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
}

void EventService::Update()
{

}

void EventService::ProcessEvents()
{
	if (IsGameWindowOpen())
	{
		while (gameWindow->pollEvent(gameEvent))
		{
			if (GameWindowWasClosed() || HasQuitGame())
			{
				gameWindow->close();
			}
		}
	}
}

bool EventService::HasQuitGame()
{
	return IsKeyboardEvent() && PressedEscapeKey();
}

bool EventService::IsKeyboardEvent()
{
	return gameEvent.type == sf::Event::KeyPressed;
}

bool EventService::PressedLeftKey()
{
	return gameEvent.key.code == sf::Keyboard::Left;
}

bool EventService::PressedRightKey()
{
	return gameEvent.key.code == sf::Keyboard::Right;
}

bool EventService::PressedEscapeKey()
{
	return gameEvent.key.code == sf::Keyboard::Escape;
}

bool EventService::IsGameWindowOpen()
{
	return gameWindow != nullptr;
}

bool EventService::GameWindowWasClosed()
{
	return gameEvent.type == sf::Event::Closed;
}











