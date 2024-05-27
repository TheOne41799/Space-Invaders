#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header//PlayerService.h"
#include "../Header/TimeService.h"


class ServiceLocator
{
private:

	GraphicService *graphicService;
	EventService *eventService;
	PlayerService *playerService;
	TimeService *timeService;

	ServiceLocator();

	~ServiceLocator();

	void CreateServices();

	void ClearAllServices();

public:
	static ServiceLocator* GetInstance();

	void Initialize();

	void Update();

	void Render();

	GraphicService* GetGraphicService();
	EventService* GetEventService();
	PlayerService* GetPlayerService();
	TimeService* GetTimeService();

};
