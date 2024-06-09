#pragma once
#include <SFML/Graphics.hpp>
#include "../Interface/IUIController.h"
#include "../UIElement/ImageView.h"
#include "../UIElement/ButtonView.h"
#include "../UIElement/TextView.h"


namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController : public Interface::IUIController
		{
		private:
			const sf::Color textColor = sf::Color::White;
			const float backgroundAlpha = 100.f;

			const float playButtonYPosition = 300.f;
			const float instructionsButtonYPosition = 500.f;
			const float quitButtonYPosition = 700.f;

			const float buttonWidth = 400.0f;
			const float buttonHeight = 140.0f;

			UIElement::ImageView* backgroundImage;

			UIElement::ButtonView* playButton;
			UIElement::ButtonView* instructionsButton;
			UIElement::ButtonView* quitButton;			

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
