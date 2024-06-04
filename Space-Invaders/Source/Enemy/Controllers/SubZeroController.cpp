#include "../../../Header/Enemy/Controllers/SubZeroController.h"
#include "../../header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;


	namespace Controller
	{
		SubZeroController::SubZeroController(EnemyType type): EnemyController(type) { }

		SubZeroController::~SubZeroController() { }

		void SubZeroController::Initialize()
		{
			EnemyController::Initialize();
			enemyModel->SetMovementDirection(MovementDirection::DOWN);
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
	}
}