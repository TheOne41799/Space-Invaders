#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Enemy/EnemyController.h"

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
		InitializeEnemySprite();
	}

	void EnemyView::InitializeEnemySprite()
	{
		if (enemyTexture.loadFromFile(enemyTexturePath))
		{
			enemySprite.setTexture(enemyTexture);
			ScaleEnemySprite();
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