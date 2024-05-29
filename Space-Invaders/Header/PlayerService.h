#pragma once
#include <SFML/Graphics.hpp>


class PlayerService
{
private:
	int health = 3;
	sf::Vector2f playerPosition = sf::Vector2f(200.0f, 200.0f);
	float playerMovementSpeed = 250.0f;
	int playerScore = 0;

	const sf::String playerTexturePath = "assets/textures/player_ship.png";

	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	sf::RenderWindow* gameWindow;

	void InitializePlayerSprite();
	void ProcessPlayerInputs();

public:
	PlayerService();
	~PlayerService();

	void Initialize();
	void Update();
	void Render();

	void MoveLeft();
	void MoveRight();
	sf::Vector2f GetPlayerPosition();
	int GetMoveSpeed();
};
