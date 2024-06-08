#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/Entity.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"


namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		FROZEN,
		DEAD
	};


	class PlayerModel
	{
	private:
		friend class PlayerController;

		friend void UI::GameplayUI::GameplayUIController::UpdateEnemiesKilledText();
		friend void UI::GameplayUI::GameplayUIController::DrawPlayerLives();

		const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.0f, 950.0f);
		const int maxPlayerLives = 3;

		sf::Vector2f currentPlayerPosition;

		PlayerState playerState;
		Entity::EntityType entityType;

		int playerScore = 0;

		static int playerLives;
		static int enemiesKilled;

		bool bShield;
		bool bRapidFire;
		bool bTrippleLaser;

	public:
		const float playerMovementSpeed = 250.0f;

		const sf::Vector2f leftMostPosition = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f rightMostPosition = sf::Vector2f(1800.0f, 950.0f);
		const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 5.f);

		const sf::Vector2f secondWeaponPositionOffset = sf::Vector2f(45.f, 0.f);
		const sf::Vector2f thirdWeaponPositionOffset = sf::Vector2f(-45.f, 0.f);

		const float shiledPowerupDuration = 10.f;
		const float rapidFirePowerupDuration = 10.f;
		const float trippleLaserPowerupDuration = 10.f;

		const float freezeDuration = 2.f;

		const float fireCooldownDuration = 0.2f;
		const float rapidFireCooldownDuration = 0.05f;
		const float trippleLaserPositionOffset = 30.f;

		static const int invinciblePlayerAlpha = 170.f;

		float elapsedShieldDuration;
		float elapsedRapidFireDuration;
		float elapsedTrippleLaserDuration;

		float elapsedFireDuration;
		float elapsedFreezeDuration;

		PlayerModel();
		~PlayerModel();

		void Initialize();
		void Reset();

		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f position);

		int GetPlayerScore();
		void SetPlayerScore(int score);

		PlayerState GetPlayerState();
		void SetPlayerState(PlayerState state);

		Entity::EntityType GetEntityType();

		bool IsShieldEnabled();
		bool IsRapidFireEnabled();
		bool IsTrippleLaserEnabled();

		void SetShieldState(bool value);
		void SetRapidFireState(bool value);
		void SetTrippleFireState(bool value);
	};
}










