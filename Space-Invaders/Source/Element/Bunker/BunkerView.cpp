#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"


namespace Elements
{
	namespace Bunker
	{		
		using namespace Global;


		BunkerView::BunkerView()
		{
		}

		BunkerView::~BunkerView()
		{
		}

		void BunkerView::Initialize(BunkerController* controller)
		{
			bunkerController = controller;
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			InitializeImage();
		}

		void BunkerView::InitializeImage()
		{
			if (bunkerTexture.loadFromFile(bunkerTexturePath))
			{
				bunkerSprite.setTexture(bunkerTexture);
				ScaleSprite();
			}
		}

		void BunkerView::ScaleSprite()
		{
			bunkerSprite.setScale(
				static_cast<float>(bunkerSpriteWidth) / bunkerSprite.getTexture()->getSize().x,
				static_cast<float>(bunkerSpriteHeight) / bunkerSprite.getTexture()->getSize().y
			);
		}

		void BunkerView::Update()
		{
			bunkerSprite.setPosition(bunkerController->GetBunkerPosition());
		}

		void BunkerView::Render()
		{
			gameWindow->draw(bunkerSprite);
		}
	}
}