#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"


namespace UI
{
	using namespace Main;
	using namespace MainMenu;


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
		InitializeControllers();
	}

	void UIService::Update()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuUIController->Update();
			break;
		}
	}

	void UIService::Render()
	{
		switch (GameService::GetGameState())
		{
		case GameState::MAIN_MENU:
			return mainMenuUIController->Render();
			break;
		}
	}

	void UIService::InitializeControllers()
	{
		mainMenuUIController->Initialize();
	}

	void UIService::Destroy()
	{
		delete(mainMenuUIController);
	}
}