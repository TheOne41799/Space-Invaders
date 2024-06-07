#pragma once
#include "../Projectile/IProjectile.h"
//#include "../Bullet/BulletConfig.h"
#include "../Entity/Entity.h"
#include "../Collision/ICollider.h"


namespace Bullet
{
    class BulletView;
    class BulletModel;

    enum class BulletType;


    class BulletController : public Projectile::IProjectile, public Collision::ICollider
    {
    protected:
        BulletView* bulletView;
        BulletModel* bulletModel;

        void UpdateProjectilePosition() override;

        void ProcessBulletCollision(ICollider* otherCollider);
        void ProcessEnemyCollision(ICollider* otherCollider);
        void ProcessPlayerCollision(ICollider* otherCollider);
        void ProcessBunkerCollision(ICollider* otherCollider);

        void MoveUp();
        void MoveDown();
        void HandleOutOfBounds();

    public:
        BulletController(BulletType type, Entity::EntityType ownerType);
        //virtual ~BulletController() override;
        virtual ~BulletController();

        void Initialize(sf::Vector2f position, MovementDirection direction) override;
        void Update() override;
        void Render() override;

        sf::Vector2f GetProjectilePosition() override;
        BulletType GetBulletType();

        Entity::EntityType GetOwnerEntityType();

        const sf::Sprite& GetColliderSprite() override;
        void OnCollision(ICollider* otherCollider) override;
    };
}
