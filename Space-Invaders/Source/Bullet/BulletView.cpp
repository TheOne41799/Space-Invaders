#include "../../Header/Bullet/BulletView.h"
#include "../../Header/Bullet/BulletController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Bullet/BulletConfig.h"


namespace Bullet
{
	using namespace Global;
	using namespace UI::UIElement;


	BulletView::BulletView() 
	{  
		CreateUIElements();
	}

	BulletView::~BulletView() 
	{ 
		Destroy();
	}

	void BulletView::Initialize(BulletController* controller)
	{
		bulletController = controller;
		//gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		//InitializeImage(bulletController->GetBulletType());

		InitializeImage();
	}

	void BulletView::CreateUIElements()
	{
		bulletImage = new ImageView();
	}

	void BulletView::InitializeImage()
	{
		bulletImage->Initialize(GetBulletTexturePath(),
								bulletSpriteWidth, bulletSpriteHeight, 
								bulletController->GetProjectilePosition());
	}

	/*void BulletView::InitializeImage(BulletType type)
	{
		switch (type)
		{
		case::Bullet::BulletType::LASER_BULLET:
			if (bulletTexture.loadFromFile(Config::laserBulletTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				ScaleImage();
			}
			break;
		case::Bullet::BulletType::FROST_BULLET:
			if (bulletTexture.loadFromFile(Config::frostBeamTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				ScaleImage();
			}
			break;
		case::Bullet::BulletType::TORPEDOE:
			if (bulletTexture.loadFromFile(Config::torpedoeTexturePath))
			{
				bulletSprite.setTexture(bulletTexture);
				ScaleImage();
			}
			break;
		}
	}

	void BulletView::ScaleImage()
	{
		bulletSprite.setScale(
			static_cast<float>(bulletSpriteWidth) / bulletSprite.getTexture()->getSize().x,
			static_cast<float>(bulletSpriteHeight) / bulletSprite.getTexture()->getSize().y
		);
	}*/

	void BulletView::Update()
	{
		//bulletSprite.setPosition(bulletController->GetProjectilePosition());

		bulletImage->SetPosition(bulletController->GetProjectilePosition());
		bulletImage->Update();
	}

	void BulletView::Render()
	{
		//gameWindow->draw(bulletSprite);

		bulletImage->Render();
	}

	const sf::Sprite& BulletView::GetBulletSprite()
	{
		// TODO: insert return statement here
	}

	sf::String BulletView::GetBulletTexturePath()
	{
		switch (bulletController->GetBulletType())
		{
		case::Bullet::BulletType::LASER_BULLET:
			return Config::laserBulletTexturePath;

		case::Bullet::BulletType::FROST_BULLET:
			return Config::frostBeamTexturePath;

		case::Bullet::BulletType::TORPEDOE:
			return Config::torpedoeTexturePath;
		}
	}

	void BulletView::Destroy()
	{
		delete (bulletImage);
	}
}
