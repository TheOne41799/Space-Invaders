#pragma once
#include "../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"


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
