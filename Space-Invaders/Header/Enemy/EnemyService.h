#pragma once
#include <vector>


namespace Enemy
{
	class EnemyController;


	class EnemyService
	{
	private:
		const float spawnInterval = 3.0f;

		std::vector<EnemyController*> enemyList;
		float spawnTimer;

		void UpdateSpawnTimer();
		void ProcessEnemySpawn();
		void Destroy();

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void SpawnEnemy();
	};
}
