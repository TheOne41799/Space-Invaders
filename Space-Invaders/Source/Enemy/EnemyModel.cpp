#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	EnemyModel::EnemyModel(EnemyType type)
	{
		enemyType = type;
		enemyState = EnemyState::PATROLLING;
		movementDirection = MovementDirection::RIGHT;
	}

	EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::Initialize()
	{
		//enemyState = EnemyState::PATROLLING;
		//movementDirection = MovementDirection::RIGHT;
		enemyPosition = referencePosition;
	}

	sf::Vector2f EnemyModel::GetEnemyPosition()
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}

	sf::Vector2f EnemyModel::GetReferencePosition()
	{
		return referencePosition;
	}

	void EnemyModel::SetReferencePosition(sf::Vector2f position)
	{
		referencePosition = position;
	}

	EnemyState EnemyModel::GetEnemyState()
	{
		return enemyState;
	}

	void EnemyModel::SetEnemyState(EnemyState state)
	{
		enemyState = state;
	}

	EnemyType EnemyModel::GetEnemyType()
	{
		return enemyType;
	}

	void EnemyModel::SetEnemyType(EnemyType type)
	{
		enemyType = type;
	}

	MovementDirection EnemyModel::GetMovementDirection()
	{
		return movementDirection;
	}

	void EnemyModel::SetMovementDirection(MovementDirection direction)
	{
		movementDirection = direction;
	}

	Entity::EntityType EnemyModel::GetEntityType()
	{
		return entityType;
	}
}