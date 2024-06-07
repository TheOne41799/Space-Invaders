#pragma once
#include <vector>
#include "SFML/System/Vector2.hpp"
#include "../Projectile/IProjectile.h"
#include "../../header/Entity/Entity.h"


namespace Bullet
{
	class BulletController;
	
	enum class BulletType;
	enum class MovementDirection;


	class BulletService
	{
	private:
		std::vector<Projectile::IProjectile*> bulletList;

		BulletController* CreateBullet(BulletType bulletType, Entity::EntityType ownerType);
		void Destroy();

	public:
		BulletService();
		virtual ~BulletService();

		void Initialize();
		void Update();
		void Render();

		BulletController* SpawnBullet(BulletType bulletType, sf::Vector2f position, 
									  MovementDirection direction,
									  Entity::EntityType ownerType);		

		void DestroyBullet(BulletController* bullet_controller);

		void Reset();
	};
}
