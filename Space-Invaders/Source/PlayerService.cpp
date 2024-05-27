#include "../Header/PlayerService.h"
#include "../Header/ServiceLocator.h"


void PlayerService::InitializePlayerSprite()
{
	if (playerTexture.loadFromFile(playerTexturePath))
	{
		playerSprite.setTexture(playerTexture);
	}
}

void PlayerService::ProcessPlayerInputs()
{
	EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

	if (eventService->IsKeyboardEvent())
	{
		if (eventService->PressedLeftKey())
		{
			MoveLeft();
		}

		if (eventService->PressedRightKey())
		{
			MoveRight();
		}
	}
}

PlayerService::PlayerService()
{
	gameWindow = nullptr;
}

PlayerService::~PlayerService() = default;

void PlayerService::Initialize()
{
	gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
	InitializePlayerSprite();
}

void PlayerService::Update()
{
	ProcessPlayerInputs();
	playerSprite.setPosition(GetPlayerPosition());
}

void PlayerService::Render()
{
	gameWindow->draw(playerSprite);
}

void PlayerService::MoveLeft()
{
	playerPosition.x -= playerMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
}

void PlayerService::MoveRight()
{
	playerPosition.x += playerMovementSpeed * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
}

sf::Vector2f PlayerService::GetPlayerPosition()
{
	return playerPosition;
}

int PlayerService::GetMoveSpeed()
{
	return playerMovementSpeed;
}




