#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../header/Collision/ICollider.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Controller;
	using namespace Collision;


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

		/*for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Update();
		}*/

		for (EnemyController* enemy : enemyList)
		{
			enemy->Update();
		}

		DestroyFlaggedEnemies();
	}

	void EnemyService::Render()
	{
		/*for (int i = 0; i < enemyList.size(); i++)
		{
			enemyList[i]->Render();
		}*/

		for (EnemyController* enemy : enemyList)
		{
			enemy->Render();
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

	EnemyController* EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());

		enemyController->Initialize();

		ServiceLocator::GetInstance()->GetCollisionService()->AddCollider(dynamic_cast<ICollider*>(enemyController));

		enemyList.push_back(enemyController);

		return enemyController;
	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		//int randomType = std::rand() % 4;

		int randomType = std::rand() % (static_cast<int>(Enemy::EnemyType::UFO) + 1);
		return static_cast<Enemy::EnemyType>(randomType);
	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType)
	{
		switch (enemyType)
		{
		case::Enemy::EnemyType::ZAPPER:
			return new ZapperController(Enemy::EnemyType::ZAPPER);

		case::Enemy::EnemyType::SUBZERO:
			return new SubZeroController(Enemy::EnemyType::SUBZERO);

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return new ThunderSnakeController(Enemy::EnemyType::THUNDER_SNAKE);

		case::Enemy::EnemyType::UFO:
			return new UFOController(Enemy::EnemyType::UFO);
		}
	}

	void EnemyService::DestroyFlaggedEnemies()
	{
		for (int i = 0; i < flaggedEnemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
										 ->RemoveCollider(dynamic_cast<ICollider*>(flaggedEnemyList[i]));

			delete (flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}

	void EnemyService::DestroyEnemy(EnemyController* enemyController)
	{
		//enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());

		//printf("Enemy Killed");

		//delete(enemyController);

		dynamic_cast<ICollider*>(enemyController)->DisableCollision();
		flaggedEnemyList.push_back(enemyController);
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), enemyController), enemyList.end());
	}	

	void EnemyService::Destroy()
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
										 ->RemoveCollider(dynamic_cast<ICollider*>(enemyList[i]));

			delete(enemyList[i]);
		}

		enemyList.clear();
	}

	void EnemyService::Reset()
	{
		Destroy();
		spawnTimer = 0.0f;
	}
}