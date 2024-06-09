#pragma once
#include "SFML/Graphics.hpp"
#include "../Collision/ICollider.h"
#include "../Powerups/PowerupConfig.h"
#include "PlayerModel.h"


namespace Player
{
	class PlayerView;

	enum class PlayerState;


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

		void DecreasePlayerLive();
		inline void IncreaseEnemiesKilled(int val) { PlayerModel::enemiesKilled += val; }

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		sf::Vector2f GetPlayerPosition();
		PlayerState GetPlayerState();

		const sf::Sprite& GetColliderSprite() override;
		void OnCollision(ICollider* other_collider) override;
	};
}
