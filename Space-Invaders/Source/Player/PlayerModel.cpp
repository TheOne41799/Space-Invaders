#include "../../Header/Player/PlayerModel.h"


namespace Player
{
	PlayerModel::PlayerModel()
	{
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
		playerScore = 0;
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
}





