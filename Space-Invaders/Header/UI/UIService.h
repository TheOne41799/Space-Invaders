#pragma once
#include "MainMenu/MainMenuUIController.h"


namespace UI
{
	class UIService
	{
	private:
		MainMenu::MainMenuUIController* mainMenuUIController;

		void CreateControllers();
		void InitializeControllers();
		void Destroy();

	public:
		UIService();
		~UIService();

		void Initialize();
		void Update();
		void Render();
	};
}
