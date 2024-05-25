#include "../Header/ServiceLocator.h"


ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	eventService = nullptr;
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
}

void ServiceLocator::ClearAllServices()
{
	delete(graphicService);
	delete(eventService);
	graphicService = nullptr;
	eventService = nullptr;
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
}

void ServiceLocator::Update()
{
	graphicService->Update();
	eventService->Update();
}

void ServiceLocator::Render()
{
	graphicService->Render();
}

GraphicService* ServiceLocator::GetGraphicService()
{
	return graphicService;
}

EventService* ServiceLocator::GetEventService()
{
	return eventService;
}

