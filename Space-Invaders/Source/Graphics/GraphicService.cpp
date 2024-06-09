#include "../../Header/Graphics/GraphicService.h"


namespace Graphics
{
	GraphicService::GraphicService()
	{
		gameWindow = nullptr;
		videoMode = nullptr;
	}

	GraphicService::~GraphicService()
	{
		OnDestroy();
	}

	void GraphicService::Initialize()
	{
		gameWindow = CreateGameWindow();
		SetFrameRate(frameRate);
	}

	sf::RenderWindow* GraphicService::CreateGameWindow()
	{
		SetVideoMode();
		return new sf::RenderWindow(*videoMode, gameWindowTitle, sf::Style::Fullscreen);
	}

	void GraphicService::SetVideoMode()
	{
		videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicService::OnDestroy()
	{
		delete(videoMode);
		delete(gameWindow);
	}

	void GraphicService::SetFrameRate(int frameRateToSet)
	{
		gameWindow->setFramerateLimit(frameRateToSet);
	}

	void GraphicService::Update()
	{

	}

	void GraphicService::Render()
	{

	}

	bool GraphicService::IsGameWindowOpen()
	{
		return gameWindow->isOpen();
	}	

	sf::RenderWindow* GraphicService::GetGameWindow()
	{
		return gameWindow;
	}
}



