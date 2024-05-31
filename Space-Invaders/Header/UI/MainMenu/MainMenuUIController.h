#pragma once
#include <SFML/Graphics.hpp>


namespace UI
{
	namespace MainMenu
	{
		class MainMenuUIController
		{
		private:
			const sf::String backgroundTexturePath = "assets/textures/space_invaders_bg.png";
			const sf::String playButtonTexturePath = "assets/textures/play_button.png";
			const sf::String instructionsButtonTexturePath = "assets/textures/instructions_button.png";
			const sf::String quitButtonTexturePath = "assets/textures/quit_button.png";

			const float buttonWidth = 400.0f;
			const float buttonHeight = 140.0f;

			sf::RenderWindow* gameWindow;

			sf::Texture backgroundTexture;
			sf::Sprite backgroundSprite;

			sf::Texture playButtonTexture;
			sf::Sprite playButtonSprite;

			sf::Texture instructionsButtonTexture;
			sf::Sprite instructionsButtonSprite;

			sf::Texture quitButtonTexture;
			sf::Sprite quitButtonSprite;

			void InitializeBackgroundImage();
			void ScaleBackgroundImage();

			void InitializeButtons();
			bool LoadButtonTexturesFromFile();
			void SetButtonSprites();

			void ScaleAllButtons();
			void ScaleButton(sf::Sprite* buttonToScale);
			void PositionButtons();
			
		public:
			MainMenuUIController();

			void Initialize();
			void Update();
			void Render();
		};
	}
}
