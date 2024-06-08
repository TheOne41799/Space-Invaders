#include "../../header/Enemy/Controllers/ThunderSnakeController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../header/Enemy/EnemyModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletConfig.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;


	namespace Controller
	{
		ThunderSnakeController::ThunderSnakeController(EnemyType type) : EnemyController(type) { }

		ThunderSnakeController::~ThunderSnakeController() { }

		void ThunderSnakeController::Initialize()
		{
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(GetInitialMovementDirection());

			horizontalMovementSpeed = thunderSnakeHorizontalMovementSpeed;
		}

		MovementDirection ThunderSnakeController::GetInitialMovementDirection()
		{
			static MovementDirection initialDirection = MovementDirection::RIGHT;

			switch (initialDirection)
			{
			case Enemy::MovementDirection::LEFT:
				initialDirection = MovementDirection::RIGHT;
				return initialDirection;

			case Enemy::MovementDirection::RIGHT:
				initialDirection = MovementDirection::LEFT;
				return initialDirection;
			}
		}

		void ThunderSnakeController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				MoveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				MoveRight();
				break;

			case::Enemy::MovementDirection::LEFT_DOWN:
				MoveDiagonalLeft();
				break;

			case::Enemy::MovementDirection::RIGHT_DOWN:
				MoveDiagonalRight();
				break;
			}
		}

		void ThunderSnakeController::MoveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.x -= thunderSnakeHorizontalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x <= enemyModel->leftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT_DOWN);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void ThunderSnakeController::MoveRight()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
			currentPosition.x += thunderSnakeHorizontalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x >= enemyModel->rightMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::LEFT_DOWN);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void ThunderSnakeController::MoveDiagonalLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.y += thunderSnakeVerticalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			currentPosition.x -= thunderSnakeHorizontalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x <= enemyModel->leftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void ThunderSnakeController::MoveDiagonalRight()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.y += thunderSnakeVerticalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			currentPosition.x += thunderSnakeHorizontalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x >= enemyModel->rightMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::LEFT);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void ThunderSnakeController::FireBullet()
		{
			ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(
											BulletType::TORPEDOE,
											enemyModel->GetEntityType(),
											enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
											Bullet::MovementDirection::DOWN);
		}

		void ThunderSnakeController::Destroy()
		{

			EnemyController::Destroy();
		}
	}
}