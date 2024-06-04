#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy
{
	class EnemyModel;
	class EnemyView;

	enum class EnemyType;
	enum class EnemyState;


	class EnemyController
	{
	protected:
		float rateOfFire = 3.f;
		float elapsedFireDuration = 0.f;

		EnemyModel* enemyModel;
		EnemyView* enemyView;

		void UpdateFireTimer();
		void ProcessBulletFire();
		virtual void FireBullet() = 0;

		virtual void Move() = 0;

		sf::Vector2f GetRandomInitialPosition();
		void HandleOutOfBounds();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		EnemyState GetEnemyState();
		EnemyType GetEnemyType();
	};
}
