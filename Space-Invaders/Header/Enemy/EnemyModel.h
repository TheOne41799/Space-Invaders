#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy
{
	enum class EnemyType;
	enum class MovementDirection;
	enum class EnemyState;


	class EnemyModel
	{
	private:
		sf::Vector2f referencePosition = sf::Vector2f(50.f, 50.f);
		sf::Vector2f enemyPosition;

		MovementDirection movementDirection;
		EnemyType enemyType;
		EnemyState enemyState;

	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		const sf::Vector2f leftMostPosition = sf::Vector2f(50.f, 50.f);
		const sf::Vector2f rightMostPosition = sf::Vector2f(1800.f, 50.f);

		const float verticalTravelDistance = 100.f;
		const float enemyMovementSpeed = 250.0f;

		const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 50.f);

		//const float horizontalMovementSpeed = 50.0f;
		//const float verticalMovementSpeed = 50.0f;

		void Initialize();

		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf::Vector2f position);

		sf::Vector2f GetReferencePosition();
		void SetReferencePosition(sf::Vector2f position);

		EnemyType GetEnemyType();
		void SetEnemyType(EnemyType type);

		EnemyState GetEnemyState();
		void SetEnemyState(EnemyState state);

		MovementDirection GetMovementDirection();
		void SetMovementDirection(MovementDirection direction);
	};
}
