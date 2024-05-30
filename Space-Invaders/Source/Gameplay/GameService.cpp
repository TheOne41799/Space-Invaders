#include "../../Header/Gameplay/GameService.h"
#include "../../Header/Graphics/GraphicService.h" //Should this be included?
#include "../../Header/Event/EventService.h" //Should this be included?


GameService::GameService()
{
	serviceLocator = nullptr;
	gameWindow = nullptr;
}

GameService::~GameService()
{
	Destroy();
}

void GameService::Initialize()
{
	serviceLocator->Initialize();
	InitializeVariables();
}

void GameService::InitializeVariables()
{
	gameWindow = serviceLocator->GetGraphicService()->GetGameWindow();
}

void GameService::Destroy()
{
	//delete serviceLocator;
	delete gameWindow;
}

void GameService::Ignite()
{
	serviceLocator = ServiceLocator::GetInstance();
	Initialize();
}

void GameService::Update()
{
	serviceLocator->GetEventService()->ProcessEvents();
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





