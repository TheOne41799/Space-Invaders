#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace Global;
	using namespace Graphics;


	EnemyView::EnemyView() { }

	EnemyView::~EnemyView() { }

	void EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializeEnemySprite(enemyController->GetEnemyType());
	}

	void EnemyView::InitializeEnemySprite(EnemyType type)
	{
		switch (type)
		{
		case::Enemy::EnemyType::SUBZERO:
			if (enemyTexture.loadFromFile(subZeroTexturePath))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		case::Enemy::EnemyType::ZAPPER:
			if (enemyTexture.loadFromFile(zapperTexturePath))
			{
				enemySprite.setTexture(enemyTexture);
				ScaleEnemySprite();
			}
			break;
		}
	}

	void EnemyView::ScaleEnemySprite()
	{
		enemySprite.setScale(
			static_cast<float>(enemySpriteWidth) / enemySprite.getTexture()->getSize().x,
			static_cast<float>(enemySpriteHeight) / enemySprite.getTexture()->getSize().y
		);
	}

	void EnemyView::Update()
	{
		enemySprite.setPosition(enemyController->GetEnemyPosition());
	}

	void EnemyView::Render()
	{
		gameWindow->draw(enemySprite);
	}
}