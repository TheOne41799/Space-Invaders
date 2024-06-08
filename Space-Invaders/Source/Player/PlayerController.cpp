#include "../../Header/Player/PlayerController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Player/PlayerView.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Entity/Entity.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Main/GameService.h"


namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Bullet;
	using namespace Entity;
	using namespace Enemy;
	using namespace Powerup;
	using namespace Sound;
	using namespace Main;
	using namespace Gameplay;


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

		BulletController* bullet_controller = dynamic_cast<BulletController*>(otherCollider);

		if (bullet_controller && bullet_controller->GetOwnerEntityType() != EntityType::PLAYER)
		{
			if (bullet_controller->GetBulletType() == BulletType::FROST_BULLET)
			{
				FreezePlayer();
			}
			else
			{
				DecreasePlayerLive();
			}

			return true;
		}
		return false;
	}

	bool PlayerController::ProcessEnemyCollision(ICollider* otherCollider)
	{
		if (playerModel->IsShieldEnabled())
		{
			return false;
		}

		EnemyController* enemy_controller = dynamic_cast<EnemyController*>(otherCollider);

		if (enemy_controller)
		{
			DecreasePlayerLive();
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
		if (elapsedShieldDuration > 0)
		{
			elapsedShieldDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsedShieldDuration <= 0)
			{
				DisableShield();
			}
		}

		if (elapsedRapidFireDuration > 0)
		{
			elapsedRapidFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsedRapidFireDuration <= 0)
			{
				DisableRapidFire();
			}
		}

		if (elapsedTrippleLaserDuration > 0)
		{
			elapsedTrippleLaserDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsedTrippleLaserDuration <= 0)
			{
				DisableTrippleLaser();
			}
		}
	}

	void PlayerController::FreezePlayer()
	{
		playerModel->SetPlayerState(PlayerState::FROZEN);
		elapsedFreezeDuration = playerModel->freezeDuration;
		playerView->SetPlayerHighlight(true);
	}

	void PlayerController::EnableShield()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_ENABLED);
		elapsedShieldDuration = playerModel->shiledPowerupDuration;
		playerModel->SetShieldState(true);
		playerView->SetPlayerHighlight(true);
	}

	void PlayerController::DisableShield()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_DISABLED);
		playerModel->SetShieldState(false);
		playerView->SetPlayerHighlight(false);
	}

	void PlayerController::EnableRapidFire()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_ENABLED);
		elapsedRapidFireDuration = playerModel->rapidFirePowerupDuration;
		playerModel->SetRapidFireState(true);
	}

	void PlayerController::DisableRapidFire()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_DISABLED);
		playerModel->SetRapidFireState(false);
	}

	void PlayerController::EnableTrippleLaser()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_ENABLED);
		elapsedTrippleLaserDuration = playerModel->trippleLaserPowerupDuration;
		playerModel->SetTrippleFireState(true);
	}

	void PlayerController::DisableTrippleLaser()
	{
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::POWERUP_DISABLED);
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
			ProcessBulletFire();
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
		if (elapsedFireDuration >= 0)
		{
			elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		}
	}

	void PlayerController::UpdateFreezeDuration()
	{
		if (elapsedFreezeDuration > 0)
		{
			elapsedFireDuration -= ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();

			if (elapsedFreezeDuration <= 0)
			{
				playerModel->SetPlayerState(PlayerState::ALIVE);
				playerView->SetPlayerHighlight(false);
			}
		}
	}

	void PlayerController::ProcessBulletFire()
	{
		if (elapsedFireDuration > 0)
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
			elapsedFireDuration = playerModel->rapidFireCooldownDuration;
		}

		else
		{
			elapsedFireDuration = playerModel->fireCooldownDuration;
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

		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BULLET_FIRE);
	}

	void PlayerController::FireBullet(sf::Vector2f position)
	{
		ServiceLocator::GetInstance()->GetBulletService()->SpawnBullet(BulletType::LASER_BULLET,
																	   playerModel->GetEntityType(),
																	   position,
																	   Bullet::MovementDirection::UP);
	}

	void PlayerController::DecreasePlayerLive()
	{
		PlayerModel::playerLives -= 1;
		if (PlayerModel::playerLives <= 0)
		{
			Reset();
		}
	}
}

