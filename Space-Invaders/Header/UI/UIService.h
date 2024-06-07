#pragma once
#include "MainMenu/MainMenuUIController.h"
#include "Interface/IUIController.h"


namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* mainMenuUIController;

		void CreateControllers();
		void InitializeControllers();
		void Destroy();

		Interface::IUIController* GetCurrentUIController();

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();

		void ShowScreen();
	};
}
