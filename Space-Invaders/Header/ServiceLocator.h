#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"
#include "../Header//PlayerService.h"


class ServiceLocator
{
private:

	GraphicService *graphicService;
	EventService *eventService;
	PlayerService* playerService;

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

};
