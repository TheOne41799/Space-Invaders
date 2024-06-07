#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h" 


namespace UI
{
	using namespace Main;
	using namespace MainMenu;
	using namespace UIElement;
	using namespace Interface;


	UIService::UIService()
	{
		mainMenuUIController = nullptr;
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		mainMenuUIController = new MainMenuUIController();
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


		/*switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuUIController->Update();
			break;
		}*/
	}

	void UIService::Render()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController)
		{
			uiController->Render();
		}


		/*switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuUIController->Render();
			break;
		}*/
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
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuUIController;

		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		delete(mainMenuUIController);
	}
}