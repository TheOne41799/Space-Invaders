#include "../../Header/Bullet/Controllers/LaserBulletController.h"


namespace Bullet
{
	namespace Controller
	{
		LaserBulletController::LaserBulletController(BulletType bulletType, Entity::EntityType ownerType)
													 : BulletController(bulletType, ownerType) { }

		LaserBulletController::~LaserBulletController() { }

		void LaserBulletController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
		}
	}
}