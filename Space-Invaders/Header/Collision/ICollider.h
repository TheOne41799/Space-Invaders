#pragma once
#include <SFML/Graphics.hpp>


namespace Collision
{
    enum class CollisionState
    {
        ENABLED,
        DISABLED,
    };


    class ICollider
    {
    private:
        CollisionState collisionState;

    public:
        ICollider();
        virtual ~ICollider();

        virtual const sf::Sprite& GetColliderSprite() = 0;
        virtual void OnCollision(ICollider* other_collider) = 0;

        void EnableCollision();
        void DisableCollision();
        CollisionState GetCollisionState();
    };
}