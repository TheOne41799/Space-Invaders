#include "../../Header/Bullet/BulletService.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Bullet/Controllers/FrostBulletController.h"
#include "../../Header/Bullet/Controllers/LaserBulletController.h"
#include "../../Header/Bullet/Controllers/TorpedoeController.h"
#include "../../Header/Collision/ICollider.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Bullet
{
	using namespace Controller;
	using namespace Projectile;
	//using namespace Entity;
	using namespace Global;
	using namespace Collision;


	BulletService::BulletService()
	{
	}

	BulletService::~BulletService()
	{
		Destroy();
	}

	void BulletService::Initialize()
	{
		bulletList.clear();
		flaggedBulletList.clear();
	}

	void BulletService::Update()
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			bulletList[i]->Update();
		}

		DestroyFlaggedBullets();
	}

	void BulletService::Render()
	{
		for (int i = 0; i < bulletList.size(); i++)
		{
			bulletList[i]->Render();
		}
	}

	BulletController* BulletService::CreateBullet(BulletType bulletType, Entity::EntityType ownerType)
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

	bool BulletService::IsValidBullet(int index, std::vector<Projectile::IProjectile*>& bulletList)
	{
		return index >= 0 && index < bulletList.size() && bulletList[index] != nullptr;
	}

	void BulletService::DestroyFlaggedBullets()
	{
		for (int i = 0; i < flaggedBulletList.size(); i++)
		{
			if (!IsValidBullet(i, flaggedBulletList))
			{
				continue;
			}

			ServiceLocator::GetInstance()->GetCollisionService()
										 ->RemoveCollider(dynamic_cast<ICollider*>(flaggedBulletList[i]));

			delete (flaggedBulletList[i]);
		}

		flaggedBulletList.clear();
	}

	void BulletService::Destroy()
	{
		/*for (int i = 0; i < bulletList.size(); i++)
		{
			delete (bulletList[i]);
		}*/

		for (int i = 0; i < bulletList.size(); i++)
		{
			if (!IsValidBullet(i, bulletList))
			{
				continue;
			}

			ServiceLocator::GetInstance()->GetCollisionService()
										 ->RemoveCollider(dynamic_cast<ICollider*>(bulletList[i]));

			delete (bulletList[i]);
		}

		bulletList.clear();
	}

	/*BulletController* BulletService::SpawnBullet(BulletType bulletType,
												 sf::Vector2f position, MovementDirection direction,
												 EntityType ownerType)
	{
		BulletController* bulletController = CreateBullet(bulletType, ownerType);

		bulletController->Initialize(position, direction);
		bulletList.push_back(bulletController);
		return bulletController;
	}*/

	BulletController* BulletService::SpawnBullet(BulletType bulletType,
												 Entity::EntityType ownerType,
												 sf::Vector2f position,
												 MovementDirection direction)
	{
		BulletController* bulletController = CreateBullet(bulletType, ownerType);
		bulletController->Initialize(position, direction);

		ServiceLocator::GetInstance()->GetCollisionService()
									 ->AddCollider(dynamic_cast<ICollider*>(bulletController));
		bulletList.push_back(bulletController);
		return bulletController;
	}

	/*void BulletService::DestroyBullet(BulletController* bullet_controller)
	{
		bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bullet_controller), bulletList.end());
		delete(bullet_controller);
	}*/

	void BulletService::DestroyBullet(BulletController* bulletController)
	{
		if (std::find(flaggedBulletList.begin(), flaggedBulletList.end(), bulletController)
					  == flaggedBulletList.end())
		{
			flaggedBulletList.push_back(bulletController);

			bulletList.erase(std::remove(bulletList.begin(), bulletList.end(), bulletController), bulletList.end());
		}
	}

	void BulletService::Reset()
	{
		Destroy();
	}
}


