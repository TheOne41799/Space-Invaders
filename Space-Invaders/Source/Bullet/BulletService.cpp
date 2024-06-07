#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"


namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;
	using namespace Entity;


	BulletService::BulletService()
	{
	}

	BulletService::~BulletService()
	{
		Destroy();
	}

	void BulletService::Initialize()
	{
	}

	void BulletService::Update()
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			bulletList[i]->Update();
		}
	}

	void BulletService::Render()
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			bulletList[i]->Render();
		}
	}

	BulletController* BulletService::CreateBullet(BulletType bulletType, EntityType ownerType)
	{
		switch (bulletType)
		{
		case::Bullet::BulletType::LASER_BULLET:
			return new LaserBulletController(Bullet::BulletType::LASER_BULLET, ownerType);

		case::Bullet::BulletType::FROST_BULLET:
			return new FrostBulletController(Bullet::BulletType::FROST_BULLET, ownerType);

		case::Bullet::BulletType::TORPEDOE:
			return new TorpedoeController(Bullet::BulletType::TORPEDOE, ownerType);
		}
	}

	void BulletService::Destroy()
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			delete (bulletList[i]);
		}
	}

	BulletController* BulletService::SpawnBullet(BulletType bulletType,
												 sf::Vector2f position, MovementDirection direction,
												 EntityType ownerType)
	{
		BulletController* bullet_controller = CreateBullet(bulletType, ownerType);

		bullet_controller->Initialize(position, direction);
		bulletList.push_back(bullet_controller);
		return bullet_controller;
	}

	void BulletService::DestroyBullet(BulletController* bullet_controller)
	{
		bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bullet_controller), bulletList.end());
		delete(bullet_controller);
	}
}


