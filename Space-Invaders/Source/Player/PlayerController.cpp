#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include <algorithm>


namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Bullet;


	PlayerController::PlayerController()
	{
		playerView = new PlayerView();
		playerModel = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete(playerView);
		delete(playerModel);
	}

	void PlayerController::Initialize()
	{
		playerModel->Initialize();
		playerView->Initialize(this);
	}

	void PlayerController::Update()
	{
		ProcessPlayerInput();
		playerView->Update();
	}

	void PlayerController::Render()
	{
		playerView->Render();
	}

	sf::Vector2f PlayerController::GetPlayerPosition()
	{
		return playerModel->GetPlayerPosition();
	}

	void PlayerController::ProcessPlayerInput()
	{
		EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftKey() || eventService->PressedAKey())
		{
			MoveLeft();
		}

		if (eventService->PressedRightKey() || eventService->PressedDKey())
		{
			MoveRight();
		}

		if (eventService->PressedLeftMouseButton())
		{
			FireBullet();
		}
	}

	void PlayerController::MoveLeft()
	{
		sf::Vector2f currentPlayerPosition = playerModel->GetPlayerPosition();
		currentPlayerPosition.x -= playerModel->playerMovementSpeed
			* ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPlayerPosition.x = std::max(currentPlayerPosition.x, playerModel->leftMostPosition.x);
		playerModel->SetPlayerPosition(currentPlayerPosition);
	}

	void PlayerController::MoveRight()
	{
		sf::Vector2f currentPlayerPosition = playerModel->GetPlayerPosition();
		currentPlayerPosition.x += playerModel->playerMovementSpeed
			* ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPlayerPosition.x = std::min(currentPlayerPosition.x, playerModel->rightMostPosition.x);
		playerModel->SetPlayerPosition(currentPlayerPosition);
	}

	void PlayerController::FireBullet()
	{
		ServiceLocator::GetInstance()->GetBulletService()
						->SpawnBullet(BulletType::LASER_BULLET,
									  playerModel->GetPlayerPosition() + playerModel->barrelPositionOffset,
									  Bullet::MovementDirection::UP);
	}
}

