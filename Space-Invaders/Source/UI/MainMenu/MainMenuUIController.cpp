#include "../../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../../Header/Main/GameService.h"
#include "../../../Header/Graphics/GraphicService.h"
#include "../../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"


namespace UI
{
	namespace MainMenu
	{
		using namespace Global;
		using namespace Graphics;
		using namespace Event;
		using namespace Main;
		using namespace Sound;


		MainMenuUIController::MainMenuUIController()
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
		}
	}
}