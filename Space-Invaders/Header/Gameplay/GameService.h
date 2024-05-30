#pragma once
#include <SFML/Graphics.hpp>
#include "../Global/ServiceLocator.h"


class GameService
{
private:
	ServiceLocator* serviceLocator;
	sf::RenderWindow* gameWindow;

	void Initialize();
	void InitializeVariables();
	void Destroy();

public:
	GameService();
	~GameService();

	void Ignite();
	void Update();
	void Render();
	bool IsRunning();
};
