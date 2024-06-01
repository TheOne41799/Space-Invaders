#pragma once


namespace Enemy
{
	class EnemyController;


	class EnemyService
	{
	private:
		void Destroy();

		EnemyController* enemy;

	public:
		EnemyService();
		virtual ~EnemyService();

		void Initialize();
		void Update();
		void Render();

		EnemyController* SpawnEnemy();

	};
}
