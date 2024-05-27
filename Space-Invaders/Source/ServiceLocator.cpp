#include "../Header/ServiceLocator.h"


ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
	playerService = nullptr;
	CreateServices();
}

ServiceLocator::~ServiceLocator()
{
	ClearAllServices();
}

void ServiceLocator::CreateServices()
{
	graphicService = new GraphicService();
	eventService = new EventService();
	playerService = new PlayerService();
}

void ServiceLocator::ClearAllServices()
{
	delete(graphicService);
	delete(eventService);
	delete(playerService);

	graphicService = nullptr;
	eventService = nullptr;
	playerService = nullptr;
}

ServiceLocator* ServiceLocator::GetInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::Initialize()
{
	graphicService->Initialize();
	eventService->Initialize();
	playerService->Initialize();
}

void ServiceLocator::Update()
{
	graphicService->Update();
	eventService->Update();
	playerService->Update();
}

void ServiceLocator::Render()
{
	graphicService->Render();
	playerService->Render();
}

GraphicService* ServiceLocator::GetGraphicService()
{
	return graphicService;
}

EventService* ServiceLocator::GetEventService()
{
	return eventService;
}

PlayerService* ServiceLocator::GetPlayerService()
{
	return playerService;
}

