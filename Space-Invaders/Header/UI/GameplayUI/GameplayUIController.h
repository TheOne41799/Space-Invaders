#pragma once
#include "../../UI/Interface/IUIController.h"
#include "../../UI/UIElement/ImageView.h"
#include "../../UI/UIElement/ButtonView.h"
#include "../../UI/UIElement/TextView.h"


namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			const float fontSize = 40.f;

			const float textYPosition = 15.f;
			const float enemiesKilledTextXPosition = 60.f;

			const float playerLivesYOffset = 25.f;
			const float playerLivesXOffset = 1850.f;
			const float playerLivesSpacing = 60.f;

			const float playerSpriteWidth = 30.f;
			const float playerSpriteHeight = 30.f;

			const sf::Color textColor = sf::Color::White;

			UI::UIElement::ImageView* playerImage;
			UI::UIElement::TextView* enemiesKilledText;

			void CreateUIElements();
			void InitializeImage();
			void InitializeText();

			void Destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void Initialize() override;
			void Update() override;
			void Render() override;
			void Show() override;

			void UpdateEnemiesKilledText();
			void DrawPlayerLives();
		};
	}
}
