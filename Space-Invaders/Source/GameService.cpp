#include "../Header/GameService.h"
#include "../Header/GraphicService.h"


GameService::GameService()
{
	serviceLocator = nullptr;
	gameWindow = nullptr;
}

GameService::~GameService()
{
	Destroy();
}

void GameService::Ignite()
{
	serviceLocator = ServiceLocator::GetInstance();
	Initialize();
}

void GameService::Update()
{
	serviceLocator->Update();
}

void GameService::Render()
{
	gameWindow->clear(serviceLocator->GetGraphicService()->GetGameWindowColor());
	serviceLocator->Render();
	gameWindow->display();
}

bool GameService::IsRunning()
{
	return serviceLocator->GetGraphicService()->IsGameWindowOpen();
}






void GameService::Initialize()
{
	//Initialize objects
}

void GameService::InitializeVariables()
{
}

void GameService::Destroy()
{
	//
}












