#include "../../Header/Global/ServiceLocator.h"


namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Player;
	using namespace Time;


	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		timeService = nullptr;
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
		timeService = new TimeService();
		eventService = new EventService();
		playerService = new PlayerService();
	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		delete(timeService);
		delete(eventService);
		delete(playerService);

		//graphicService = nullptr;
		//eventService = nullptr;
		//playerService = nullptr;
		//timeService = nullptr;
	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{
		graphicService->Initialize();
		timeService->Initialize();
		eventService->Initialize();
		playerService->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicService->Update();
		timeService->Update();
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

	TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}
}

