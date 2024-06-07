#include "../../Header/Powerups/PowerupService.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../header/Collision/ICollider.h"
#include "../../Header/Powerups/Controllers/OutscalBombController.h"
#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../Header/Powerups/Controllers/TrippleLaserController.h"


namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;
	using namespace Collision;


	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() 
	{ 
		Destroy();
	}

	void PowerupService::Initialize() { }

	void PowerupService::Update()
	{
		/*for (int i = 0; i < powerupList.size(); i++)
		{
			powerupList[i]->Update();
		}*/

		for (Collectible::ICollectible* powerup : powerupList)
		{
			powerup->Update();
		}

		DestroyFlaggedPowerup();
	}

	void PowerupService::Render()
	{
		/*for (int i = 0; i < powerupList.size(); i++)
		{
			powerupList[i]->Render();
		}*/

		for (Collectible::ICollectible* powerup : powerupList)
		{
			powerup->Render();
		}
	}

	PowerupController* PowerupService::CreatePowerup(PowerupType powerupType)
	{
		switch (powerupType)
		{
		case::Powerup::PowerupType::SHIELD:
			return new ShieldController(Powerup::PowerupType::SHIELD);

		case::Powerup::PowerupType::RAPID_FIRE:
			return new RapidFireController(Powerup::PowerupType::RAPID_FIRE);

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return new TrippleLaserController(Powerup::PowerupType::TRIPPLE_LASER);

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return new OutscalBombController(Powerup::PowerupType::OUTSCAL_BOMB);
		}
	}

	PowerupController* PowerupService::SpawnPowerup(PowerupType powerupType, sf::Vector2f position)
	{
		PowerupController* powerup_controller = CreatePowerup(powerupType);

		powerup_controller->Initialize(position);
		powerupList.push_back(powerup_controller);
		return powerup_controller;
	}

	void PowerupService::DestroyFlaggedPowerup()
	{
		for (Collectible::ICollectible* powerup : flaggedPowerupList)
		{
			delete (powerup);
		}

		flaggedPowerupList.clear();
	}

	void PowerupService::DestroyPowerup(PowerupController* powerupController)
	{
		/*powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerup_controller),
									  powerupList.end());
		delete(powerup_controller);*/

		ServiceLocator::GetInstance()->GetCollisionService()
						->RemoveCollider(dynamic_cast<ICollider*>(powerupController));

		flaggedPowerupList.push_back(powerupController);
		powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerupController), powerupList.end());
	}

	void PowerupService::Destroy()
	{
		/*for (int i = 0; i < powerupList.size(); i++)
		{
			delete (powerupList[i]);
		}*/

		for (Collectible::ICollectible* powerup : powerupList)
		{
			delete (powerup);
		}
	}
}
