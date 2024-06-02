#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy
{
	class EnemyModel;
	class EnemyView;


	class EnemyController
	{
	private:
		EnemyModel* enemyModel;
		EnemyView* enemyView;

		virtual void Move();
		void MoveLeft();
		void MoveRight();
		void MoveDown();

	public:
		EnemyController();
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
	};
}
