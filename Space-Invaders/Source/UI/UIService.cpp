#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"


namespace UI
{
	//using namespace Main;
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
		mainMenuUIController->Update();
	}

	void UIService::Render()
	{
		mainMenuUIController->Render();
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