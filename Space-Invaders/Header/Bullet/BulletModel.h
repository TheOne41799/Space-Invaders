#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Entity/Entity.h"


namespace Bullet
{
    enum class BulletType;
    enum class MovementDirection;


    class BulletModel
    {
    private:
        float movementSpeed = 300.f;
        sf::Vector2f bulletPosition;

        BulletType bulletType;
        MovementDirection movementDirection;

        Entity::EntityType ownerType;

    public:

        BulletModel(BulletType type, Entity::EntityType ownerType);
        ~BulletModel();

        void Initialize(sf::Vector2f position, MovementDirection direction);

        sf::Vector2f GetBulletPosition();
        void SetBulletPosition(sf::Vector2f position);

        BulletType GetBulletType();
        Entity::EntityType GetOwnerEntityType();
        //void SetBulletType(BulletType type);

        MovementDirection GetMovementDirection();
        void SetMovementDirection(MovementDirection direction);

        float GetMovementSpeed();
        void SetMovementSpeed(float speed);        
    };
}
