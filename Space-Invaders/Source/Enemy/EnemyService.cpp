#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;


	EnemyService::EnemyService()
	{
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	EnemyService::~EnemyService()
	{
		Destroy();
	}

	void EnemyService::Initialize()
	{
		spawnTimer = spawnInterval;
	}

	void EnemyService::Update()
	{
		UpdateSpawnTimer();
		ProcessEnemySpawn();

		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Update();
		}
	}

	void EnemyService::Render()
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Render();
		}
	}

	void EnemyService::UpdateSpawnTimer()
	{
		spawnTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::ProcessEnemySpawn()
	{
		if (spawnTimer >= spawnInterval)
		{
			SpawnEnemy();
			spawnTimer = 0.0f;
		}
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType)
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO);
		}
	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 3;
		return static_cast<Enemy::EnemyType>(randomType);
	}

	EnemyController* EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());

		enemyController->Initialize();

		enemyList.push_back(enemyController);

		return enemyController;
	}

	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());

		delete(enemyController);
	}

	void EnemyService::Destroy()
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			delete(enemyList[i]);
		}
	}
}