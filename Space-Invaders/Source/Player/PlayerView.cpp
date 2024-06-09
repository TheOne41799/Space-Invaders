#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Player/PlayerModel.h"


namespace Player
{
	using namespace Global;
	using namespace UI::UIElement;


	PlayerView::PlayerView()
	{
		CreateUIElements();
	}

	PlayerView::~PlayerView()
	{
		Destroy();
	}

	void PlayerView::Initialize(PlayerController* controller)
	{
		playerController = controller;
		InitializeImage();
	}

	void PlayerView::CreateUIElements()
	{
		playerImage = new ImageView();
	}

	void PlayerView::InitializeImage()
	{
		playerImage->Initialize(Config::playerTexturePath,
								playerSpriteWidth, playerSpriteHeight, playerController->GetPlayerPosition());
	}

	void PlayerView::Update()
	{
		playerImage->SetPosition(playerController->GetPlayerPosition());
		playerImage->Update();
	}

	void PlayerView::Render()
	{
		playerImage->Render();
	}

	void PlayerView::Destroy()
	{
		delete(playerImage);
	}

	const sf::Sprite& PlayerView::GetPlayerSprite()
	{
		return playerImage->GetSprite();
	}

	void PlayerView::SetPlayerHighlight(bool b_highlight)
	{
		if (b_highlight) playerImage->SetImageAlpha(PlayerModel::invinciblePlayerAlpha);
		else playerImage->SetImageAlpha(255);
	}
}