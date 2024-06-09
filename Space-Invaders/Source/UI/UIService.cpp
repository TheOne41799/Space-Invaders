#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h" 


namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace UIElement;
	using namespace Interface;
	using namespace GameplayUI;
	using namespace SplashScreen;


	UIService::UIService()
	{
		mainMenuUIController = nullptr;
		gameplayUIController = nullptr;
		splashScreenUIController = nullptr;
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		mainMenuUIController = new MainMenuUIController();
		gameplayUIController = new GameplayUIController();
		splashScreenUIController = new SplashScreenUIController();
	}

	UIService::~UIService()
	{
		Destroy();
	}

	void UIService::Initialize()
	{
		TextView::InitializeTextView();
		InitializeControllers();
	}

	void UIService::Update()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Update();
		}
	}

	void UIService::Render()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Render();
		}
	}

	void UIService::ShowScreen()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Show();
		}
	}

	void UIService::InitializeControllers()
	{
		mainMenuUIController->Initialize();
		gameplayUIController->Initialize();
		splashScreenUIController->Initialize();
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splashScreenUIController;
		case GameState::MAIN_MENU:
			return mainMenuUIController;
		case GameState::GAMEPLAY:
			return gameplayUIController;		
		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		delete(mainMenuUIController);
		delete(gameplayUIController);
		delete(splashScreenUIController);
	}
}