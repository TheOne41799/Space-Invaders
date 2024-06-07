#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include <algorithm>
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/Entity.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerups/PowerupController.h"


namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Bullet;
	using namespace Time;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;


	PlayerController::PlayerController()
	{
		playerView = new PlayerView();
		playerModel = new PlayerModel();
	}

	PlayerController::~PlayerController()
	{
		delete(playerView);
		delete(playerModel);
	}

	void PlayerController::Initialize()
	{
		playerModel->Initialize();
		playerView->Initialize(this);
	}

	void PlayerController::Update()
	{
		/*ProcessPlayerInput();
		playerView->Update();*/

		switch (playerModel->GetPlayerState())
		{
		case::Player::PlayerState::ALIVE:
			ProcessPlayerInput();
			break;

		case::Player::PlayerState::FROZEN:
			UpdateFreezeDuration();
			break;
		}

		UpdatePowerupDuration();
		UpdateFireDuration();
		playerView->Update();
	}

	void PlayerController::Render()
	{
		playerView->Render();
	}

	void PlayerController::Reset()
	{
		playerModel->Reset();
	}

	sf::Vector2f PlayerController::GetPlayerPosition()
	{
		return playerModel->GetPlayerPosition();
	}

	int PlayerController::GetPlayerScore()
	{
		return playerModel->GetPlayerScore();
	}

	PlayerState PlayerController::GetPlayerState()
	{
		return playerModel->GetPlayerState();
	}

	const sf::Sprite& PlayerController::GetColliderSprite()
	{
		return playerView->GetPlayerSprite();
	}

	void PlayerController::OnCollision(ICollider* otherCollider)
	{
		if (ProcessPowerupCollision(otherCollider))
		{
			return;
		}

		if (ProcessBulletCollision(otherCollider))
		{
			return;
		}

		ProcessEnemyCollision(otherCollider);
	}

	bool PlayerController::ProcessBulletCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
		{
			return false;
		}

		BulletController* bulletController = dynamic_cast<BulletController*>(otherCollider);

		if (bulletController && bulletController->GetOwnerEntityType() != EntityType::PLAYER)
		{
			if (bulletController->GetBulletType() == BulletType::FROST_BULLET)
			{
				playerModel->SetPlayerState(PlayerState::FROZEN);
				playerModel->elapsedFreezeDuration = playerModel->freezeDuration;
			}
			else
			{
				ServiceLocator::GetInstance()->GetGameplayService()->Restart();
			}

			return true;
		}
	}

	bool PlayerController::ProcessEnemyCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
		{
			return false;
		}

		EnemyController* enemyController = dynamic_cast<EnemyController*>(otherCollider);

		if (enemyController)
		{
			ServiceLocator::GetInstance()->GetGameplayService()->Restart();
			return true;
		}

		return false;
	}

	bool PlayerController::ProcessPowerupCollision(ICollider* otherCollider)
	{
		PowerupController* powerupController = dynamic_cast<PowerupController*>(otherCollider);

		if (powerupController)
		{
			return true;
		}

		return false;
	}

	void PlayerController::UpdatePowerupDuration()
	{
		if (playerModel->elapsedShieldDuration > 0)
		{
			playerModel->elapsedShieldDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedShieldDuration <= 0)
			{
				DisableShield();
			}
		}

		if (playerModel->elapsedRapidFireDuration > 0)
		{
			playerModel->elapsedRapidFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedRapidFireDuration <= 0)
			{
				DisableRapidFire();
			}
		}

		if (playerModel->elapsedTrippleLaserDuration > 0)
		{
			playerModel->elapsedTrippleLaserDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedTrippleLaserDuration <= 0)
			{
				DisableTrippleLaser();
			}
		}
	}

	void PlayerController::EnableShield()
	{
		playerModel->elapsedShieldDuration = playerModel->shiledPowerupDuration;
		playerModel->SetShieldState(true);
	}

	void PlayerController::DisableShield()
	{
		playerModel->SetShieldState(false);
	}

	void PlayerController::EnableRapidFire()
	{
		playerModel->elapsedRapidFireDuration = playerModel->rapidFirePowerupDuration;
		playerModel->SetRapidFireState(true);
	}

	void PlayerController::DisableRapidFire()
	{
		playerModel->SetRapidFireState(false);
	}

	void PlayerController::EnableTrippleLaser()
	{
		playerModel->elapsedTrippleLaserDuration = playerModel->trippleLaserPowerupDuration;
		playerModel->SetTrippleFireState(true);
	}

	void PlayerController::DisableTrippleLaser()
	{
		playerModel->SetTrippleFireState(false);
	}

	void PlayerController::ProcessPlayerInput()
	{
		EventService* eventService = ServiceLocator::GetInstance()->GetEventService();

		if (eventService->PressedLeftKey() || eventService->PressedAKey())
		{
			MoveLeft();
		}

		if (eventService->PressedRightKey() || eventService->PressedDKey())
		{
			MoveRight();
		}

		if (eventService->PressedLeftMouseButton())
		{
			FireBullet();
		}
	}

	void PlayerController::MoveLeft()
	{
		sf::Vector2f currentPlayerPosition = playerModel->GetPlayerPosition();
		currentPlayerPosition.x -= playerModel->playerMovementSpeed
			* ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPlayerPosition.x = std::max(currentPlayerPosition.x, playerModel->leftMostPosition.x);
		playerModel->SetPlayerPosition(currentPlayerPosition);
	}

	void PlayerController::MoveRight()
	{
		sf::Vector2f currentPlayerPosition = playerModel->GetPlayerPosition();
		currentPlayerPosition.x += playerModel->playerMovementSpeed
			* ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

		currentPlayerPosition.x = std::min(currentPlayerPosition.x, playerModel->rightMostPosition.x);
		playerModel->SetPlayerPosition(currentPlayerPosition);
	}

	void PlayerController::UpdateFireDuration()
	{
		if (playerModel->elapsedFireDuration >= 0)
		{
			playerModel->elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
	}

	void PlayerController::UpdateFreezeDuration()
	{
		if (playerModel->elapsedFreezeDuration > 0)
		{
			playerModel->elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (playerModel->elapsedFreezeDuration <= 0)
			{
				playerModel->SetPlayerState(PlayerState::ALIVE);
			}
		}
	}

	void PlayerController::ProcessBulletFire()
	{
		if (playerModel->elapsedFireDuration > 0)
		{
			return;
		}

		if (playerModel->IsTrippleLaserEnabled())
		{
			FireBullet(true);
		}

		else
		{
			FireBullet();
		}

		if (playerModel->IsRapidFireEnabled())
		{
			playerModel->elapsedFireDuration = playerModel->rapidFireCooldownDuration;
		}

		else
		{
			playerModel->elapsedFireDuration = playerModel->fireCooldownDuration;
		}
	}

	void PlayerController::FireBullet(bool bTrippleLaser)
	{
		sf::Vector2f bulletPosition = playerModel->GetPlayerPosition() + playerModel->barrelPositionOffset;

		FireBullet(bulletPosition);

		if (bTrippleLaser)
		{
			FireBullet(bulletPosition + playerModel->secondWeaponPositionOffset);
			FireBullet(bulletPosition + playerModel->thirdWeaponPositionOffset);
		}
	}

	void PlayerController::FireBullet(sf::Vector2f position)
	{
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
																	   position,
																	   Bullet::MovementDirection::UP,
																	   playerModel->GetEntityType());

		//original
		/*ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
																	   playerModel->GetEntityType(),
																	   position,
																	   Bullet::MovementDirection::UP);*/
	}
}

