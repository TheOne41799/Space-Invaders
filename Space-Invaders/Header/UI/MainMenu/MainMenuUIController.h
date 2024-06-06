#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/IUIController.h"
#include "../UIElement/ImageView.h"
#include "../UIElement/ButtonView.h"


namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const float buttonWidth = 400.0f;
			const float buttonHeight = 140.0f;

			const float playButtonYPosition = 300.f;
			const float instructionsButtonYPosition = 500.f;
			const float quitButtonYPosition = 700.f;

			const float backgroundAlpha = 85.f;

			UIElement::ImageView* backgroundImage;

			UIElement::ButtonView* playButton;
			UIElement::ButtonView* instructionsButton;
			UIElement::ButtonView* quitButton;

			//sf::RenderWindow* gameWindow;

			/*sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;

			sf::Texture playButtonTexture;
			sf::Sprite playButtonSprite;

			sf::Texture instructionsButtonTexture;
			sf::Sprite instructionsButtonSprite;

			sf::Texture quitButtonTexture;
			sf::Sprite quitButtonSprite;*/

			/*void InitializeBackgroundImage();
			void ScaleBackgroundImage();

			void InitializeButtons();
			bool LoadButtonTexturesFromFile();
			void SetButtonSprites();

			void ScaleAllButtons();
			void ScaleButton(sf::Sprite* buttonToScale);
			void PositionButtons();

			void ProcessButtonInteractions();
			bool ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition);*/

			void CreateImage();
			void CreateButtons();
			void InitializeBackgroundImage();
			void InitializeButtons();
			void RegisterButtonCallback();

			void PlayButtonCallback();
			void InstructionsButtonCallback();
			void QuitButtonCallback();

			void Destroy();
			
		public:
			MainMenuUIController();
			~MainMenuUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;
		};
	}
}
