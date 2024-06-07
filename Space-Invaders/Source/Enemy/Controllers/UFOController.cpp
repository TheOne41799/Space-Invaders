#include "../../Header/Enemy/Controllers/UFOController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerups/PowerupService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Entity/Entity.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;
	using namespace Entity;


	namespace Controller
	{
		UFOController::UFOController(EnemyType type) : EnemyController(type) { }

		UFOController::~UFOController() { }

		void UFOController::Initialize()
		{
			EnemyController::Initialize();
		}

		void UFOController::FireBullet()
		{
		}

		Powerup::PowerupType UFOController::GetRandomPowerupType()
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));

			int random_value = std::rand() % (static_cast<int>(Powerup::PowerupType::OUTSCAL_BOMB) + 1);
			return static_cast<Powerup::PowerupType>(random_value);
		}

		void UFOController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::LEFT:
				MoveLeft();
				break;

			case::Enemy::MovementDirection::RIGHT:
				MoveRight();
				break;
			}

		}

		void UFOController::MoveLeft()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.x -= enemyModel->horizontalMovementSpeed
											 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x <= enemyModel->leftMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::RIGHT);
				enemyModel->SetReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void UFOController::MoveRight()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.x += enemyModel->horizontalMovementSpeed
											 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (currentPosition.x >= enemyModel->rightMostPosition.x)
			{
				enemyModel->SetMovementDirection(MovementDirection::LEFT);
				enemyModel->SetReferencePosition(currentPosition);
			}
			else
			{
				enemyModel->SetEnemyPosition(currentPosition);
			}
		}

		void UFOController::OnCollision(ICollider* otherCollider)
		{
			EnemyController::OnCollision(otherCollider);

			BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

			if (bulletController && bulletController->GetOwnerEntityType() != EntityType::ENEMY)
			{
				ServiceLocator::GetInstance()->GetPowerupService()
								->SpawnPowerup(GetRandomPowerupType(), enemyModel->GetEnemyPosition());
				return;
			}
		}
	}
}