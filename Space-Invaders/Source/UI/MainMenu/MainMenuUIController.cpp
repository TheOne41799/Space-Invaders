#include "../../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../../Header/Main/GameService.h"
#include "../../../Header/Graphics/GraphicService.h"
#include "../../../Header/Global/ServiceLocator.h"



namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Graphics;
		using namespace Event;
		using namespace Main;


		MainMenuUIController::MainMenuUIController()
		{
			gameWindow = nullptr;
		}

		void UI::MainMenu::MainMenuUIController::Initialize()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		}

		void MainMenuUIController::Update()
		{
		}

		void MainMenuUIController::Render()
		{
		}
	}
}