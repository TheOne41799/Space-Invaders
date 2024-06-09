#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/Entity.h"


namespace Enemy
{
	enum class EnemyType;
	enum class EnemyState;
	enum class MovementDirection;


	class EnemyModel
	{
	private:
		sf::Vector2f referencePosition = sf::Vector2f(50.f, 100.f);
		sf::Vector2f enemyPosition;

		Entity::EntityType entityType;
		EnemyType enemyType;
		EnemyState enemyState;		
		MovementDirection movementDirection;

	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 100.f);
		const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 100.f);
		const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 50.f);

		void Initialize();

		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf::Vector2f position);

		sf::Vector2f GetReferencePosition();
		void SetReferencePosition(sf::Vector2f position);

		EnemyState GetEnemyState();
		void SetEnemyState(EnemyState state);

		EnemyType GetEnemyType();
		void SetEnemyType(EnemyType type);

		MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection direction);

		Entity::EntityType GetEntityType();
	};
}
