#pragma once
#include "SFML/Graphics.hpp"
#include "../Collision/ICollider.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Player/PlayerModel.h"


namespace Player
{
	enum class PlayerState;

	class PlayerView;
	//class PlayerModel;


	class PlayerController : public Collision::ICollider
	{
	private:
		float elapsedShieldDuration;
		float elapsedRapidFireDuration;
		float elapsedTrippleLaserDuration;

		float elapsedFireDuration;
		float elapsedFreezeDuration;

		PlayerView* playerView;
		PlayerModel* playerModel;

		void ProcessPlayerInput();
		void MoveLeft();
		void MoveRight();

		bool ProcessBulletCollision(ICollider* otherCollider);
		bool ProcessPowerupCollision(ICollider* otherCollider);
		bool ProcessEnemyCollision(ICollider* otherCollider);
		void UpdateFreezeDuration();
		void FreezePlayer();

		void UpdateFireDuration();
		void ProcessBulletFire();
		void FireBullet(bool bTrippleLaser = false);
		void FireBullet(sf::Vector2f position);

		void UpdatePowerupDuration();

		void DisableShield();
		void DisableRapidFire();
		void DisableTrippleLaser();

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		sf::Vector2f GetPlayerPosition();
		int GetPlayerScore();
		PlayerState GetPlayerState();

		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* other_collider) override;
	};
}
