#pragma once
#include "Player/PlayerController.h"


class PlayerService
{
private:
	PlayerController* playerController;

public:
	PlayerService();
	~PlayerService();

	void Initialize();
	void Update();
	void Render();
};
