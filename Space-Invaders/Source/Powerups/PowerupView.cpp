#include "../../Header/Powerups/PowerupView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
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
		//gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		//InitializeImage(powerupController->GetPowerupType());

		InitializeImage();
	}

	void PowerupView::CreateUIElements()
	{
		powerupImage = new ImageView();
	}

	/*void PowerupView::InitializeImage(PowerupType type)
	{
		switch (type)
		{
		case::Powerup::PowerupType::TRIPPLE_LASER:
			if (powerupTexture.loadFromFile(Config::trippleLaserTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::SHIELD:
			if (powerupTexture.loadFromFile(Config::shieldTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::RAPID_FIRE:
			if (powerupTexture.loadFromFile(Config::rapidFireTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		case::Powerup::PowerupType::OUTSCAL_BOMB:
			if (powerupTexture.loadFromFile(Config::outscalBombTexturePath))
			{
				powerupSprite.setTexture(powerupTexture);
				ScaleImage();
			}
			break;
		}
	}*/

	void PowerupView::InitializeImage()
	{
		powerupImage->Initialize(GetPowerupTexturePath(),
								 powerupSpriteWidth, powerupSpriteHeight,
								 powerupController->GetCollectiblePosition());
	}

	/*void PowerupView::ScaleImage()
	{
		powerupSprite.setScale(
			static_cast<float>(powerupSpriteWidth) / powerupSprite.getTexture()->getSize().x,
			static_cast<float>(powerupSpriteHeight) / powerupSprite.getTexture()->getSize().y
		);
	}*/

	void PowerupView::Update()
	{
		//powerupSprite.setPosition(powerupController->GetCollectiblePosition());

		powerupImage->SetPosition(powerupController->GetCollectiblePosition());
		powerupImage->Update();
	}

	void PowerupView::Render()
	{
		//gameWindow->draw(powerupSprite);

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