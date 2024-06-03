#pragma once
#include <SFML/Graphics.hpp>


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
            sf::RenderWindow* gameWindow;

            sf::Texture bunkerTexture;
            sf::Sprite bunkerSprite;

            const sf::String bunkerTexturePath = "assets/textures/bunker.png";

            void ScaleSprite();
            void InitializeImage();

        public:
            BunkerView();
            ~BunkerView();

            void Initialize(BunkerController* controller);
            void Update();
            void Render();
		};


	}
}