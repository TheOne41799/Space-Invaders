#pragma once
#include "..//Projectile/IProjectile.h"
#include "../Bullet/BulletConfig.h"
#include "../../Header/Entity/Entity.h"


namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;


    class BulletController : public Projectile::IProjectile
    {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

        void UpdateProjectilePosition() override;
        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType type, Entity::EntityType ownerType);
        virtual ~BulletController() override;

        void Initialize(sf::Vector2f position, MovementDirection direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();

        Entity::EntityType GetOwnerEntityType();
    };
}
