#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Element/Bunker/BunkerController.h"


namespace Elements
{
	namespace Bunker
	{		
		using namespace Global;
		using namespace Graphics;
		using namespace UI::UIElement;


		BunkerView::BunkerView()
		{
			CreateUIElements();
		}

		BunkerView::~BunkerView()
		{
			Destroy();
		}

		void BunkerView::Initialize(BunkerController* controller)
		{
			bunkerController = controller;
			InitializeImage();
		}		

		void BunkerView::CreateUIElements()
		{
			bunkerImage = new ImageView();
		}

		void BunkerView::InitializeImage()
		{
			bunkerImage->Initialize(Config::bunkerTexturePath,
									bunkerSpriteWidth, bunkerSpriteHeight,
									bunkerController->GetBunkerPosition());
		}

		void BunkerView::Update()
		{
			bunkerImage->Update();
		}

		void BunkerView::Render()
		{
			bunkerImage->Render();
		}	

		const sf::Sprite& BunkerView::GetBunkerSprite()
		{
			return bunkerImage->GetSprite();
		}

		void BunkerView::Destroy()
		{
			delete(bunkerImage);
		}
	}
}