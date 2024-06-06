#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Graphics/GraphicService.h"
#include "../../Header/Global/Config.h"


namespace Gameplay
{
	using namespace Global;
	using namespace Graphics;
	using namespace UI::UIElement;


	GameplayView::GameplayView() 
	{
		backgroundImage = new ImageView();
	}

	GameplayView::~GameplayView()
	{
		delete (backgroundImage);
	}

	void GameplayView::Initialize()
	{
		//gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		//InitializeBackgroundSprite();

		InitializeBackgroundImage();
	}

	/*void GameplayView::InitializeBackgroundSprite()
	{
		if (backgroundTexture.loadFromFile(Config::backgroundTexturePath))
		{
			backgroundSprite.setTexture(backgroundTexture);
			ScaleBackgroundSprite();
		}
	}
	void GameplayView::ScaleBackgroundSprite()
	{
		backgroundSprite.setScale(
			static_cast<float>(gameWindow->getSize().x) / backgroundSprite.getTexture()->getSize().x,
			static_cast<float>(gameWindow->getSize().y) / backgroundSprite.getTexture()->getSize().y
		);
	}*/

	void GameplayView::InitializeBackgroundImage()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

		backgroundImage->Initialize(Config::backgroundTexturePath,
									gameWindow->getSize().x,
									gameWindow->getSize().y,
									sf::Vector2f(0, 0));
	}

	void GameplayView::Update()
	{
		backgroundImage->Update();
	}

	void GameplayView::Render()
	{
		//gameWindow->draw(backgroundSprite);

		backgroundImage->Render();
	}
}



