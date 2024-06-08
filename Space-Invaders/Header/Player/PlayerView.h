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

		void SetPlayerHighlight(bool bHighlight);
		const sf::Sprite& GetPlayerSprite();		
	};
}
