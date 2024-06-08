#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"  //This led to a small error - chapter - Using Forward Declarations
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Collision/ICollider.h"


namespace Player
{
	PlayerService::PlayerService()
	{
		playerController = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		delete(playerController);
	}

	void PlayerService::Initialize()
	{
		playerController->Initialize();
	}

	void PlayerService::Update()
	{
		playerController->Update();
	}

	void PlayerService::Render()
	{
		playerController->Render();
	}

	void PlayerService::EnableShield()
	{
		playerController->EnableShield();
	}

	void PlayerService::EnableRapidFire()
	{
		playerController->EnableRapidFire();
	}

	void PlayerService::EnableTrippleLaser()
	{
		playerController->EnableTrippleLaser();
	}

	void PlayerService::Reset()
	{
		playerController->Reset();
	}

	void PlayerService::IncreaseEnemiesKilled(int val)
	{
		playerController->IncreaseEnemiesKilled(val);
	}
}



