#pragma once
#include "../Header/GraphicService.h"
#include "../Header/EventService.h"


class ServiceLocator
{
private:

	GraphicService *graphicService;
	EventService *eventService;

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

};
