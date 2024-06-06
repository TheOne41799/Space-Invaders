#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Global/Config.h"


namespace Enemy
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;


	EnemyView::EnemyView() 
	{ 
		CreateUIElements();
	}

	EnemyView::~EnemyView() 
	{
		Destroy();
	}

	void EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		//gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		//InitializeEnemySprite(enemyController->GetEnemyType());

		InitializeImage();
	}

	void EnemyView::CreateUIElements()
	{
		enemyImage = new ImageView();
	}

	void EnemyView::InitializeImage()
	{
		enemyImage->Initialize(GetEnemyTexturePath(),
							   enemySpriteWidth, enemySpriteHeight,
							   enemyController->GetEnemyPosition());
	}

	/*void EnemyView::InitializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case::Enemy::EnemyType::SUBZERO:
			if (enemyTexture.loadFromFile(Config::subZeroTexturePath))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::ZAPPER:
			if (enemyTexture.loadFromFile(Config::zapperTexturePath))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::THUNDER_SNAKE:
			if (enemyTexture.loadFromFile(Config::thunderSnakeTexturePath))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::UFO:
			if (enemyTexture.loadFromFile(Config::ufoTexturePath))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		}
	}*/

	/*void EnemyView::ScaleEnemySprite()
	{
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeight) / enemySprite.getTexture()->getSize().y
		);
	}*/

	void EnemyView::Update()
	{
		//enemySprite.setPosition(enemyController->GetEnemyPosition());

		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		enemyImage->Update();
	}

	void EnemyView::Render()
	{
		//gameWindow->draw(enemySprite);

		enemyImage->Render();
	}

	sf::String EnemyView::GetEnemyTexturePath()
	{
		switch (enemyController->GetEnemyType())
		{
		case::Enemy::EnemyType::ZAPPER:
			return Config::zapperTexturePath;

		case::Enemy::EnemyType::THUNDER_SNAKE:
			return Config::thunderSnakeTexturePath;

		case::Enemy::EnemyType::SUBZERO:
			return Config::subZeroTexturePath;

		case::Enemy::EnemyType::UFO:
			return Config::ufoTexturePath;
		}
	}

	void EnemyView::Destroy()
	{
		delete (enemyImage);
	}
}




