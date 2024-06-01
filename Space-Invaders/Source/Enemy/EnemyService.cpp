#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;


	EnemyService::EnemyService()
	{
		enemy = nullptr;
	}

	EnemyService::~EnemyService()
	{
		Destroy();
	}

	void EnemyService::Initialize()
	{
		SpawnEnemy();
	}

	void EnemyService::Update()
	{
	}

	void EnemyService::Render()
	{
		enemy->Render();
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		enemy = new EnemyController();
		enemy->Initialize();

		return enemy;
	}

	void EnemyService::Destroy()
	{
		delete(enemy);
	}
}