#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Gameplay/GameplayController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Player;
	using namespace Enemy;
	using namespace Elements;
	using namespace Bullet;


	GameplayService::GameplayService()
	{ 
		gameplayController = new GameplayController();
	}

	GameplayService::~GameplayService()
	{ 
		delete (gameplayController); 
	}

	void GameplayService::Initialize()
	{ 
		gameplayController->Initialize();
	}

	void GameplayService::Update()
	{ 
		gameplayController->Update(); 
	}

	void GameplayService::Render() 
	{
		gameplayController->Render(); 
	}

	void GameplayService::Restart()
	{
		ServiceLocator::GetInstance()->GetPlayerService()->Reset();
		ServiceLocator::GetInstance()->GetEnemyService()->Reset();
		ServiceLocator::GetInstance()->GetBulletService()->Reset();
		ServiceLocator::GetInstance()->GetElementService()->Reset();
	}
}