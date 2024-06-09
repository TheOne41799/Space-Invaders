#pragma once
#include <SFML/Graphics.hpp>
#include "../../UI/UIElement/ImageView.h"


namespace Elements
{
	namespace Bunker
	{
        class BunkerController;


		class BunkerView
		{
        private:
            const float bunkerSpriteWidth = 80.f;
            const float bunkerSpriteHeight = 80.f;

            BunkerController* bunkerController;
            UI::UIElement::ImageView* bunkerImage;

            void CreateUIElements();
            void InitializeImage();

            void Destroy();

        public:
            BunkerView();
            ~BunkerView();

            void Initialize(BunkerController* controller);
            void Update();
            void Render();

            const sf::Sprite& GetBunkerSprite();
		};
	}
}