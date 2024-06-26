#pragma once
#include "../../Header/Bullet/BulletController.h"


namespace Bullet
{
    namespace Controller
    {
        class TorpedoeController : public BulletController
        {
        private:
            const float torpedoMovementSpeed = 200.f;

        public:
            TorpedoeController(BulletType bulletType, Entity::EntityType ownerType);
            ~TorpedoeController();

            void Initialize(sf::Vector2f position, MovementDirection direction) override;
        };
    }
}
