#include "../../Header/Graphics/GraphicService.h"


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
	gameWindow->setFramerateLimit(frameRate);
}

sf::RenderWindow* GraphicService::CreateGameWindow()
{
	SetVideoMode();
	return new sf::RenderWindow(*videoMode, gameWindowTitle);
}

void GraphicService::SetVideoMode()
{
	videoMode = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
}

void GraphicService::OnDestroy()
{
	delete(videoMode); //This is the same as 'delete videoMode;'
	delete(gameWindow);
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

sf::Color GraphicService::GetGameWindowColor()
{
	return gameWindowColor;
}



