#pragma once
#include <SFML/Graphics.hpp>
#include "BunkerModel.h"
#include "../../Collision/ICollider.h"


namespace Elements
{
	namespace Bunker
	{
		class BunkerView;


        class BunkerController : public Collision::ICollider
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

            const sf::Sprite& GetColliderSprite() override;
            void OnCollision(ICollider* otherCollider) override;
        };
	}
}



