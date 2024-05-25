#pragma once
#include "../Header/GraphicService.h"


class ServiceLocator
{
private:

	GraphicService *graphicService;

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

};
