#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Global/Config.h"


namespace Elements
{
	namespace Bunker
	{		
		using namespace Global;
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
			//gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			//InitializeImage();

			InitializeImage();
		}

		/*void BunkerView::InitializeImage()
		{
			if (bunkerTexture.loadFromFile(Config::bunkerTexturePath))
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
		}*/

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
			//bunkerSprite.setPosition(bunkerController->GetBunkerPosition());

			bunkerImage->Update();
		}

		void BunkerView::Render()
		{
			//gameWindow->draw(bunkerSprite);

			bunkerImage->Render();
		}		

		void BunkerView::Destroy()
		{
			delete(bunkerImage);
		}
	}
}