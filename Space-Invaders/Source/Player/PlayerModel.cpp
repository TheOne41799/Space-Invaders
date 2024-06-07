#include "../../Header/Player/PlayerModel.h"


namespace Player
{
	PlayerModel::PlayerModel()
	{
		entityType = Entity::EntityType::PLAYER;
	}

	PlayerModel::~PlayerModel()
	{
	}

	void PlayerModel::Initialize()
	{
		Reset();
	}

	void PlayerModel::Reset()
	{
		playerState = PlayerState::ALIVE;
		currentPlayerPosition = initialPlayerPosition;
		//playerScore = 0;

		bShield = false;
		bRapidFire = false;
		bTrippleLaser = false;
	}

	sf::Vector2f PlayerModel::GetPlayerPosition()
	{
		return currentPlayerPosition;
	}

	void PlayerModel::SetPlayerPosition(sf::Vector2f position)
	{
		currentPlayerPosition = position;
	}

	int PlayerModel::GetPlayerScore()
	{
		return playerScore;
	}

	void PlayerModel::SetPlayerScore(int score)
	{
		playerScore = score;
	}

	PlayerState PlayerModel::GetPlayerState()
	{
		return playerState;
	}

	void PlayerModel::SetPlayerState(PlayerState state)
	{
		playerState = state;
	}

	Entity::EntityType PlayerModel::GetEntityType()
	{
		return entityType;
	}

	bool PlayerModel::IsShieldEnabled()
	{
		return bShield;
	}

	bool PlayerModel::IsRapidFireEnabled()
	{
		return bRapidFire;
	}

	bool PlayerModel::IsTrippleLaserEnabled()
	{
		return bTrippleLaser;
	}

	void PlayerModel::SetShieldState(bool value)
	{
		bShield = value;
	}

	void PlayerModel::SetRapidFireState(bool value)
	{
		bRapidFire = value;
	}

	void PlayerModel::SetTrippleFireState(bool value)
	{
		bTrippleLaser = value;
	}
}





