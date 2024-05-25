#include "../Header/ServiceLocator.h"


ServiceLocator::ServiceLocator()
{
	graphicService = nullptr;
	CreateServices();
}

ServiceLocator::~ServiceLocator()
{
	ClearAllServices();
}

void ServiceLocator::CreateServices()
{
	graphicService = new GraphicService();
}

void ServiceLocator::ClearAllServices()
{
	delete(graphicService);
	graphicService = nullptr;
}

ServiceLocator* ServiceLocator::GetInstance()
{
	static ServiceLocator instance;
	return &instance;
}

void ServiceLocator::Initialize()
{
	graphicService->Initialize();
}

void ServiceLocator::Update()
{
	graphicService->Update();
}

void ServiceLocator::Render()
{
	graphicService->Render();
}

GraphicService* ServiceLocator::GetGraphicService()
{
	return graphicService;
}

