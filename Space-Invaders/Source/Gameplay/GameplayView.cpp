#include "../../header/Gameplay/GameplayView.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../header/Graphics/GraphicService.h"


namespace Gameplay
{
	using namespace Global;
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
		InitializeBackgroundImage();
	}

	void GameplayView::InitializeBackgroundImage()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

		backgroundImage->Initialize(Config::backgroundTexturePath,
									gameWindow->getSize().x,
									gameWindow->getSize().y,
									sf::Vector2f(0, 0));

		//background_image->setImageAlpha(background_alpha); -> looks ugly with the transperency
	}

	void GameplayView::Update()
	{
		backgroundImage->Update();
	}

	void GameplayView::Render()
	{
		backgroundImage->Render();
	}
}



