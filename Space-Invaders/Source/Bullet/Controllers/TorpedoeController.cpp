#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Bullet/BulletModel.h"


namespace Bullet
{
	namespace Controller
	{
		TorpedoeController::TorpedoeController(BulletType type, Entity::EntityType ownerType)
											   : BulletController(type, ownerType) { }

		TorpedoeController::~TorpedoeController() { }

		void TorpedoeController::Initialize(sf::Vector2f position, MovementDirection direction)
		{
			BulletController::Initialize(position, direction);
			bulletModel->SetMovementSpeed(torpedoMovementSpeed);
		}
	}
}