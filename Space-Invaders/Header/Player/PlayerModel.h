#pragma once
#include <SFML/Graphics.hpp>
#include "../Entity/Entity.h"
#include "../UI/GameplayUI/GameplayUIController.h"


namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		FROZEN,
		DEAD,
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

		Entity::EntityType entityType;
		PlayerState playerState;

		static int playerLives;
		static int enemiesKilled;

		bool bShield;
		bool bRapidFire;
		bool bTrippleLaser;

	public:
		const sf::Vector2f leftMostPosition = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f rightMostPosition = sf::Vector2f(1800.0f, 950.0f);
		const sf::Vector2f barrelPositionOffset = sf::Vector2f(20.f, 5.f);
		const sf::Vector2f secondWeaponPositionOffset = sf::Vector2f(45.f, 0.f);
		const sf::Vector2f thirdWeaponPositionOffset = sf::Vector2f(-45.f, 0.f);

		const float shiledPowerupDuration = 10.f;
		const float rapidFirePowerupDuration = 10.f;
		const float trippleLaserPowerupDuration = 10.f;

		const float freezeDuration = 1.5f;

		const float fireCooldownDuration = 0.2f;
		const float rapidFireCooldownDuration = 0.05f;
		const float trippleLaserPositionOffset = 30.f;

		const float playerMovementSpeed = 250.0f;
		static const int invinciblePlayerAlpha = 170.f;

		PlayerModel();
		~PlayerModel();

		void Initialize();
		void Reset();

		sf::Vector2f GetPlayerPosition();
		void SetPlayerPosition(sf::Vector2f position);

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










