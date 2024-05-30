#include "../../Header/Player/PlayerService.h"
#include "../../Header/Player/PlayerController.h"  //This led to a small error - chapter - Using Forward Declarations


PlayerService::PlayerService()
{
	playerController = new PlayerController();
}

PlayerService::~PlayerService()
{
	delete(playerController);
}

void PlayerService::Initialize()
{
	playerController->Initialize();
}

void PlayerService::Update()
{
	playerController->Update();
}

void PlayerService::Render()
{
	playerController->Render();
}




