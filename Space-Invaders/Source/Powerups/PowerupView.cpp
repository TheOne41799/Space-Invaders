#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"
#include "../../Header/Powerups/PowerupController.h"
#include "../../Header/Powerups/PowerupConfig.h"


namespace Powerup
{
	using namespace Global;
	using namespace UI::UIElement;


	PowerupView::PowerupView() 
	{
		CreateUIElements();
	}

	PowerupView::~PowerupView() 
	{
		Destroy();
	}

	void PowerupView::Initialize(PowerupController* controller)
	{
		powerupController = controller;
		InitializeImage();
	}

	void PowerupView::CreateUIElements()
	{
		powerupImage = new ImageView();
	}
	
	void PowerupView::InitializeImage()
	{
		powerupImage->Initialize(GetPowerupTexturePath(),
								 powerupSpriteWidth, powerupSpriteHeight,
								 powerupController->GetCollectiblePosition());
	}

	void PowerupView::Update()
	{
		powerupImage->SetPosition(powerupController->GetCollectiblePosition());
		powerupImage->Update();
	}

	void PowerupView::Render()
	{
		powerupImage->Render();
	}

	sf::String PowerupView::GetPowerupTexturePath()
	{
		switch (powerupController->GetPowerupType())
		{
		case::Powerup::PowerupType::SHIELD:
			return Config::shieldTexturePath;

		case::Powerup::PowerupType::TRIPPLE_LASER:
			return Config::trippleLaserTexturePath;

		case::Powerup::PowerupType::RAPID_FIRE:
			return Config::rapidFireTexturePath;

		case::Powerup::PowerupType::OUTSCAL_BOMB:
			return Config::outscalBombTexturePath;
		}
	}

	const sf::Sprite& PowerupView::GetPowerupSprite()
	{
		return powerupImage->GetSprite();
	}

	void PowerupView::Destroy()
	{
		delete(powerupImage);
	}
}