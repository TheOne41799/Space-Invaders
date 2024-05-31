#pragma once
#include <SFML/Graphics.hpp>


namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};


	class PlayerModel
	{
	private:
		const sf::Vector2f initialPlayerPosition = sf::Vector2f(950.0f, 950.0f);
		sf::Vector2f currentPlayerPosition;

		PlayerState playerState;

		int playerScore = 0;

	public:
		const float playerMovementSpeed = 250.0f;

		const sf::Vector2f leftMostPosition = sf::Vector2f(50.0f, 950.0f);
		const sf::Vector2f rightMostPosition = sf::Vector2f(1800.0f, 950.0f);

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
	};
}










