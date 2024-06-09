#pragma once
#include <vector>


namespace Enemy
{
	class EnemyController;

	enum class EnemyType;


	class EnemyService
	{
	private:
		const float spawnInterval = 2.0f;

		std::vector<EnemyController*> enemyList;
		std::vector<EnemyController*> flaggedEnemyList;
		float spawnTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType();
		EnemyController* CreateEnemy(EnemyType enemyType);
		void DestroyFlaggedEnemies();
		void Destroy();

	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemyController);
	};
}
