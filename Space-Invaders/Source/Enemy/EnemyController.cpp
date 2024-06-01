#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;


	EnemyController::EnemyController()
	{
		enemyModel = new EnemyModel();
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemyModel);
		delete(enemyView);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyView->Initialize(this);
	}

	void EnemyController::Update()
	{
		Move();
		enemyView->Update();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

	void EnemyController::Move()
	{
		switch (enemyModel->GetMovementDirection())
		{
		case::Enemy::MovementDirection::LEFT:
			MoveLeft();
			break;

		case::Enemy::MovementDirection::RIGHT:
			MoveRight();
			break;

		case::Enemy::MovementDirection::DOWN:
			MoveDown();
			break;
		}
	}

	void EnemyController::MoveLeft()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

		currentPosition.x -= enemyModel->enemyMovementSpeed
							 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.x <= enemyModel->leftMostPosition.x)
		{
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			enemyModel->SetReferencePosition(currentPosition);
		}
		else
		{
			enemyModel->SetEnemyPosition(currentPosition);
		}
	}

	void EnemyController::MoveRight()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

		currentPosition.x += enemyModel->enemyMovementSpeed
							 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.x >= enemyModel->rightMostPosition.x)
		{
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			enemyModel->SetReferencePosition(currentPosition);
		}
		else
		{
			enemyModel->SetEnemyPosition(currentPosition);
		}
	}

	void EnemyController::MoveDown()
	{
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

		currentPosition.y += enemyModel->enemyMovementSpeed
							 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		if (currentPosition.y >= enemyModel->GetReferencePosition().y + enemyModel->verticalTravelDistance)
		{
			if (enemyModel->GetReferencePosition().x <= enemyModel->leftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemyModel->SetMovementDirection(MovementDirection::LEFT);
			}
		}
		else
		{
			enemyModel->SetEnemyPosition(currentPosition);
		}
	}
}






