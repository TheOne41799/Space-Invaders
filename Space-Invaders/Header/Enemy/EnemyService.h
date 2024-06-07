#pragma once
#include <vector>


namespace Enemy
{
	class EnemyController;

	enum class EnemyType;


	class EnemyService
	{
	private:
		const float spawnInterval = 3.0f;

		std::vector<EnemyController*> enemyList;
		float spawnTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		EnemyType GetRandomEnemyType();
		EnemyController* CreateEnemy(EnemyType enemyType);
		void Destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy();
		void DestroyEnemy(EnemyController* enemyController);

		void Reset();
	};
}
