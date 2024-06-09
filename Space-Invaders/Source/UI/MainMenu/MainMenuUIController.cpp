#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Main;
		using namespace Gameplay;
		using namespace Graphics;
		using namespace Event;
		using namespace UIElement;
		using namespace Sound;


		MainMenuUIController::MainMenuUIController()
		{
			CreateImage();
			CreateButtons();
		}

		MainMenuUIController::~MainMenuUIController()
		{
			Destroy();
		}

		void MainMenuUIController::Initialize()
		{
			InitializeBackgroundImage();
			InitializeButtons();
			RegisterButtonCallback();
		}

		void MainMenuUIController::CreateImage()
		{
			backgroundImage = new ImageView();
		}

		void MainMenuUIController::CreateButtons()
		{
			playButton = new ButtonView();
			instructionsButton = new ButtonView();
			quitButton = new ButtonView();
		}

		void MainMenuUIController::InitializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

			backgroundImage->Initialize(Config::backgroundTexturePath,
				game_window->getSize().x, game_window->getSize().y,
				sf::Vector2f(0, 0));

			backgroundImage->SetImageAlpha(backgroundAlpha);
		}

		void MainMenuUIController::InitializeButtons()
		{
			playButton->Initialize("Play Button",
				Config::playButtonTexturePath,
				buttonWidth, buttonHeight,
				sf::Vector2f(0, playButtonYPosition));

			instructionsButton->Initialize("Instructions Button",
				Config::instructionsButtonTexturePath,
				buttonWidth, buttonHeight,
				sf::Vector2f(0, instructionsButtonYPosition));

			quitButton->Initialize("Quit Button",
				Config::quitButtonTexturePath,
				buttonWidth, buttonHeight,
				sf::Vector2f(0, quitButtonYPosition));

			playButton->SetCentreAlinged();
			instructionsButton->SetCentreAlinged();
			quitButton->SetCentreAlinged();
		}

		void MainMenuUIController::RegisterButtonCallback()
		{
			playButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::PlayButtonCallback, this));

			instructionsButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::InstructionsButtonCallback,
				this));

			quitButton->RegisterCallbackFuntion(std::bind(&MainMenuUIController::QuitButtonCallback, this));
		}

		void MainMenuUIController::PlayButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
			GameService::SetGameState(GameState::GAMEPLAY);
			ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
		}

		void MainMenuUIController::InstructionsButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
			GameService::SetGameState(GameState::INSTRUCTIONS);
		}

		void MainMenuUIController::QuitButtonCallback()
		{
			ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow()->close();
		}

		void MainMenuUIController::Update()
		{
			backgroundImage->Update();
			playButton->Update();
			instructionsButton->Update();
			quitButton->Update();
		}

		void MainMenuUIController::Render()
		{
			backgroundImage->Render();
			playButton->Render();
			instructionsButton->Render();
			quitButton->Render();
		}

		void MainMenuUIController::Show()
		{
			backgroundImage->Show();
			playButton->Show();
			instructionsButton->Show();
			quitButton->Show();
		}

		void MainMenuUIController::Destroy()
		{
			delete (playButton);
			delete (instructionsButton);
			delete (quitButton);
			delete (backgroundImage);
		}
	}
}