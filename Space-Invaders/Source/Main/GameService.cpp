#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/UI/UIService.h"


namespace Main
{
	using namespace Global;

	GameState GameService::currentState = GameState::BOOT;


	GameService::GameService()
	{
		serviceLocator = nullptr;
		gameWindow = nullptr;
	}

	GameService::~GameService()
	{
		
	}

	void GameService::Initialize()
	{
		serviceLocator->Initialize();
		InitializeVariables();
		ShowSplashScreen();
	}

	void GameService::InitializeVariables()
	{
		gameWindow = serviceLocator->GetGraphicService()->GetGameWindow();
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
		gameWindow->clear();
		serviceLocator->Render();
		gameWindow->display();
	}	

	bool GameService::IsRunning()
	{
		return serviceLocator->GetGraphicService()->IsGameWindowOpen();
	}

	void GameService::SetGameState(GameState newState)
	{
		currentState = newState;
	}

	GameState GameService::GetGameState()
	{
		return currentState;
	}

	void GameService::ShowSplashScreen()
	{
		SetGameState(GameState::SPLASH_SCREEN);
		ServiceLocator::GetInstance()->GetUIService()->ShowScreen();
	}
}





