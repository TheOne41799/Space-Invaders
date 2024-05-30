#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include <algorithm>


namespace Player
{
	using namespace Global;


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
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			MoveLeft();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			MoveRight();
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
}

