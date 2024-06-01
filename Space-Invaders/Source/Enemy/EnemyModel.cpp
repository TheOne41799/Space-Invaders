#include "../../Header/Enemy/EnemyModel.h"


namespace Enemy
{
	EnemyModel::EnemyModel()
	{
	}

	EnemyModel::~EnemyModel()
	{
	}

	void EnemyModel::Initialize()
	{
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
}