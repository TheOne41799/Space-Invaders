#pragma once
#include "MainMenu/MainMenuUIController.h"
#include "GameplayUI/GameplayUIController.h"
#include "Interface/IUIController.h"


namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* mainMenuUIController;
		GameplayUI::GameplayUIController* gameplayUIController;

		void CreateControllers();
		void InitializeControllers();

		Interface::IUIController* GetCurrentUIController();

		void Destroy();		

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();

		void ShowScreen();
	};
}
