#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"


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

	void EnemyView::Update()
	{
		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		enemyImage->Update();
	}

	void EnemyView::Render()
	{
		enemyImage->Render();
	}

	const sf::Sprite& EnemyView::GetEnemySprite()
	{
		return enemyImage->GetSprite();
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




