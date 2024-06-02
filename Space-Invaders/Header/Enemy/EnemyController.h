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
		EnemyModel* enemyModel;
		EnemyView* enemyView;

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
