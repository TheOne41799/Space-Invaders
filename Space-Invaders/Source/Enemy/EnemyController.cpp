#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../header/Enemy/EnemyConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../header/Entity/Entity.h"
#include "../../header/Bullet/BulletController.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Sound/SoundService.h"


namespace Enemy
{
	using namespace Global;
	using namespace Time;
	using namespace Bullet;
	using namespace Collision;
	using namespace Entity;
	using namespace Player;
	using namespace Sound;


	EnemyController::EnemyController(EnemyType type)
	{
		enemyModel = new EnemyModel(type);
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
		enemyModel->SetEnemyPosition(GetRandomInitialPosition());
		enemyView->Initialize(this);
	}

	void EnemyController::Update()
	{
		Move();
		UpdateFireTimer();
		ProcessBulletFire();
		enemyView->Update();
		//HandleOutOfBounds();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}	

	void EnemyController::UpdateFireTimer()
	{
		elapsedFireDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyController::ProcessBulletFire()
	{
		if (elapsedFireDuration >= rateOfFire)
		{
			FireBullet();
			elapsedFireDuration = 0.f;
		}
	}

	sf::Vector2f EnemyController::GetRandomInitialPosition()
	{
		float xOffsetDistance = (std::rand() % static_cast<int>
								  (enemyModel->rightMostPosition.x - enemyModel->leftMostPosition.x));

		float xPosition = enemyModel->leftMostPosition.x + xOffsetDistance;
		float yPosition = enemyModel->leftMostPosition.y;

		return sf::Vector2f(xPosition, yPosition);
	}

	/*void EnemyController::HandleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();

		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->getSize();

		if (enemyPosition.x < 0 || enemyPosition.x > windowSize.x ||
			enemyPosition.y < 0 || enemyPosition.y > windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
		}
	}*/

	/*void EnemyController::Move()
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
	}*/

	/*void EnemyController::MoveLeft()
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
	}*/

	/*void EnemyController::MoveRight()
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
	}*/

	/*void EnemyController::MoveDown()
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
	}*/

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

	EnemyState EnemyController::GetEnemyState()
	{
		return enemyModel->GetEnemyState();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetEnemyType();
	}

	const sf::Sprite& EnemyController::GetColliderSprite()
	{
		return enemyView->GetEnemySprite();
	}

	void EnemyController::OnCollision(ICollider* otherCollider)
	{
		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

		if (bulletController && bulletController->GetOwnerEntityType() != EntityType::ENEMY)
		{
			Destroy();
			return;
		}

		PlayerController* playerController = dynamic_cast<PlayerController*>(otherCollider);

		if (playerController)
		{
			Destroy();
			return;
		}
	}

	void EnemyController::Destroy()
	{
		ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);
	}
}






