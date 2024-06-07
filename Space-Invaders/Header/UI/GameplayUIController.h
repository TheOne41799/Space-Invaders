#pragma once
#include "../../header/UI/Interface/IUIController.h"
#include "../../header/UI/UIElement/ImageView.h"
#include "../../header/UI/UIElement/ButtonView.h"
#include "../../header/UI/UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			// Constants:
			const float font_size = 40.f;

			const float text_y_position = 15.f;
			const float enemies_killed_text_x_position = 60.f;

			const float player_lives_y_offset = 25.f;
			const float player_lives_x_offset = 1850.f;
			const float player_lives_spacing = 60.f;

			const float player_sprite_width = 30.f;
			const float player_sprite_height = 30.f;

			const sf::Color text_color = sf::Color::White;

			UI::UIElement::ImageView* player_image;
			UI::UIElement::TextView* enemies_killed_text;

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
