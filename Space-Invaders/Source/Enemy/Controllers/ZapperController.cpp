#include "../../../Header/Enemy/Controllers/ZapperController.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;
	using namespace Bullet;


	namespace Controller
	{
		ZapperController::ZapperController(EnemyType type) : EnemyController(type) { }

		ZapperController::~ZapperController() { }

		void ZapperController::Initialize()
		{
			EnemyController::Initialize();;
		}

		void ZapperController::Move()
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

		void ZapperController::MoveLeft()
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

		void ZapperController::MoveRight()
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

		void ZapperController::MoveDown()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.y += enemyModel->enemyMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.y >= enemyModel->GetReferencePosition().y + verticalTravelDistance)
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

		void ZapperController::FireBullet()
		{
			ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(
											BulletType::LASER_BULLET,
											enemyModel->GetEntityType(),
											enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
											Bullet::MovementDirection::DOWN);
		}
	}
}