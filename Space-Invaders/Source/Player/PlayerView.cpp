#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"


namespace Player
{
	using namespace Global;


	PlayerView::PlayerView()
	{
	}

	PlayerView::~PlayerView()
	{
	}

	void PlayerView::Initialize(PlayerController* controller)
	{
		playerController = controller;
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		InitializePlayerSprite();
	}

	void PlayerView::InitializePlayerSprite()
	{
		if (playerTexture.loadFromFile(playerTexturePath))
		{
			playerSprite.setTexture(playerTexture);
			ScalePlayerSprite();
		}
	}

	void PlayerView::ScalePlayerSprite()
	{
		playerSprite.setScale(
			static_cast<float>(playerSpriteWidth) / playerSprite.getTexture()->getSize().x,
			static_cast<float>(playerSpriteHeight) / playerSprite.getTexture()->getSize().y
		);
	}

	void PlayerView::Update()
	{
		playerSprite.setPosition(playerController->GetPlayerPosition());
	}

	void PlayerView::Render()
	{
		gameWindow->draw(playerSprite);
	}
}