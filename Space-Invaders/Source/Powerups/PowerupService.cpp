#include "../../Header/Powerups/PowerupService.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Powerups/Controllers/OutscalBombController.h"
#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../Header/Powerups/Controllers/TrippleLaserController.h"


namespace Powerup
{
	using namespace Global;
	using namespace Controller;
	using namespace Collectible;


	PowerupService::PowerupService() { }

	PowerupService::~PowerupService() 
	{ 
		Destroy();
	}

	void PowerupService::Initialize() { }

	void PowerupService::Update()
	{
		for (int i = 0; i < powerupList.size(); i++)
		{
			powerupList[i]->Update();
		}
	}

	void PowerupService::Render()
	{
		for (int i = 0; i < powerupList.size(); i++)
		{
			powerupList[i]->Render();
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

	void PowerupService::DestroyPowerup(PowerupController* powerup_controller)
	{
		powerupList.erase(std::remove(powerupList.begin(), powerupList.end(), powerup_controller),
									  powerupList.end());
		delete(powerup_controller);
	}

	void PowerupService::Destroy()
	{
		for (int i = 0; i < powerupList.size(); i++)
		{
			delete (powerupList[i]);
		}
	}
}
