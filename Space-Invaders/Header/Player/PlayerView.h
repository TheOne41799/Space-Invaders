#pragma once
#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		const float playerSpriteWidth = 60.0f;
		const float playerSpriteHeight = 60.0f;

		//sf::RenderWindow* gameWindow;

		//sf::Texture playerTexture;
		//sf::Sprite playerSprite;

		//void InitializePlayerSprite();
		//void ScalePlayerSprite();

		PlayerController* playerController;
		UI::UIElement::ImageView* playerImage;

		void CreateUIElements();
		void InitializeImage();

		void Destroy();


	public:
		PlayerView();
		~PlayerView();

		void Initialize(PlayerController* controller);
		void Update();
		void Render();

		const sf::Sprite& GetPlayerSprite();
	};
}
