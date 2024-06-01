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

	public:
		EnemyController();
		~EnemyController();

		void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
	};
}
