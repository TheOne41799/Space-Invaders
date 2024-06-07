#include "../../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../../Header/Main/GameService.h"
#include "../../../Header/Graphics/GraphicService.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Event/EventService.h"


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		//using namespace Graphics;
		//using namespace Event;
		using namespace Main;
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
		}

		void MainMenuUIController::InstructionsButtonCallback()
		{
			ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
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

			ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
		}

		void MainMenuUIController::Destroy()
		{
			delete (playButton);
			delete (instructionsButton);
			delete (quitButton);
			delete (backgroundImage);
		}






		/*MainMenuUIController::MainMenuUIController()
		{
			gameWindow = nullptr;
		}

		void UI::MainMenu::MainMenuUIController::Initialize()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeBackgroundImage();
			InitializeButtons();
		}

		void MainMenuUIController::Update()
		{
			ProcessButtonInteractions();
		}

		void MainMenuUIController::Render()
		{
			gameWindow->draw(backgroundSprite);
			gameWindow->draw(playButtonSprite);
			gameWindow->draw(instructionsButtonSprite);
			gameWindow->draw(quitButtonSprite);
		}

		void MainMenuUIController::InitializeBackgroundImage()
		{
			if (backgroundTexture.loadFromFile(Config::backgroundTexturePath))
			{
				backgroundSprite.setTexture(backgroundTexture);
				ScaleBackgroundImage();
			}
		}

		void MainMenuUIController::ScaleBackgroundImage()
		{
			backgroundSprite.setScale(
				static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
				static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
			);
		}

		void MainMenuUIController::InitializeButtons()
		{
			if (LoadButtonTexturesFromFile())
			{
				SetButtonSprites();
				ScaleAllButtons();
				PositionButtons();
			}
		}

		bool MainMenuUIController::LoadButtonTexturesFromFile()
		{
			return playButtonTexture.loadFromFile(Config::playButtonTexturePath) &&
				instructionsButtonTexture.loadFromFile(Config::instructionsButtonTexturePath) &&
				quitButtonTexture.loadFromFile(Config::quitButtonTexturePath);
		}

		void MainMenuUIController::SetButtonSprites()
		{
			playButtonSprite.setTexture(playButtonTexture);
			instructionsButtonSprite.setTexture(instructionsButtonTexture);
			quitButtonSprite.setTexture(quitButtonTexture);
		}

		void MainMenuUIController::ScaleAllButtons()
		{
			ScaleButton(&playButtonSprite);
			ScaleButton(&instructionsButtonSprite);
			ScaleButton(&quitButtonSprite);
		}

		void MainMenuUIController::ScaleButton(sf::Sprite* buttonToScale)
		{
			buttonToScale->setScale(
				buttonWidth/buttonToScale->getTexture()->getSize().x,
				buttonHeight/buttonToScale->getTexture()->getSize().y
			);

		}

		void MainMenuUIController::PositionButtons()
		{
			float x_position = (static_cast<float>(gameWindow->getSize().x) / 2) - buttonWidth / 2;

			playButtonSprite.setPosition({ x_position, 300.0f });
			instructionsButtonSprite.setPosition({ x_position, 500.0f });
			quitButtonSprite.setPosition({ x_position, 700.0f });
		}

		void MainMenuUIController::ProcessButtonInteractions()
		{
			sf::Vector2f mousePosition = sf::Vector2f(sf::Mouse::getPosition(*gameWindow));

			if (ClickedButton(&playButtonSprite, mousePosition))
			{
				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(SoundType::BUTTON_CLICK);
				ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
				GameService::SetGameState(GameState::GAMEPLAY);
			}

			if (ClickedButton(&instructionsButtonSprite, mousePosition))
			{
				printf("Clicked Instruction Button \\n");
			}

			if (ClickedButton(&quitButtonSprite, mousePosition))
			{
				gameWindow->close();
			}
		}

		bool MainMenuUIController::ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition)
		{
			EventService* eventService = ServiceLocator::GetInstance()->GetEventService();
			return eventService->PressedLeftMouseButton() && buttonSprite->getGlobalBounds().contains(mousePosition);
		}*/
	}
}