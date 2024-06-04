#include "../../Header/Bullet/BulletController.h"


namespace Bullet
{
	BulletController::BulletController(BulletType type)
	{
	}

	BulletController::~BulletController()
	{
	}

	void BulletController::UpdateProjectilePosition()
	{
	}

	void BulletController::MoveUp()
	{
	}

	void BulletController::MoveDown()
	{
	}

	void BulletController::HandleOutOfBounds()
	{
	}
	
	void BulletController::Initialize(sf::Vector2f position, Bullet::MovementDirection direction)
	{
	}

	void BulletController::Update()
	{
	}

	void BulletController::Render()
	{
	}

	sf::Vector2f BulletController::GetProjectilePosition()
	{
		return sf::Vector2f();
	}

	BulletType BulletController::GetBulletType()
	{
		return BulletType();
	}
}