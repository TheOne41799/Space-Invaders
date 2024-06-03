#pragma once
#include <SFML/Graphics.hpp>
#include "BunkerModel.h"


namespace Elements
{
	namespace Bunker
	{
		class BunkerView;


        class BunkerController
        {
        private:
            BunkerView* bunkerView;
            BunkerData bunkerData;

        public:
            BunkerController();
            ~BunkerController();

            void Initialize(BunkerData data);
            void Update();
            void Render();

            sf::Vector2f GetBunkerPosition();
        };
	}
}



