#include "../../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Bullet/BulletConfig.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;


	namespace Controller
	{
		SubZeroController::SubZeroController(EnemyType type): EnemyController(type) { }

		SubZeroController::~SubZeroController() { }

		void SubZeroController::Initialize()
		{
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
			rateOfFire = subZeroRateOfFire;
			verticalMovementSpeed = subZeroVerticalMovementSpeed;
		}

		void SubZeroController::Move()
		{
			switch (enemyModel->GetMovementDirection())
			{
			case::Enemy::MovementDirection::DOWN:
				MoveDown();
				break;
			}
		}

		void SubZeroController::MoveDown()
		{
			sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();

			currentPosition.y += verticalMovementSpeed
								 * ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			enemyModel->SetEnemyPosition(currentPosition);
		}

		void SubZeroController::FireBullet()
		{
			ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(
											BulletType::FROST_BULLET,
											enemyModel->GetEntityType(),
											enemyModel->GetEnemyPosition() + enemyModel->barrelPositionOffset,
						  					Bullet::MovementDirection::DOWN);
		}

		void SubZeroController::Destroy()
		{

			EnemyController::Destroy();
		}
	}
}