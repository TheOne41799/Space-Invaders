#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Bullet/BulletModel.h"


namespace Bullet
{
	namespace Controller
	{
		TorpedoeController::TorpedoeController(BulletType bulletType, Entity::EntityType ownerType)
											   : BulletController(bulletType, ownerType) { }

		TorpedoeController::~TorpedoeController() { }

		void TorpedoeController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
			bulletModel->SetMovementSpeed(torpedoMovementSpeed);
		}
	}
}