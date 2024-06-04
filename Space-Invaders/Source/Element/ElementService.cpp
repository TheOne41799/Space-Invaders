#include "../../Header/Element/ElementService.h"


namespace Elements
{	
	ElementService::ElementService()
	{
	}

	ElementService::~ElementService()
	{
		Destroy();
	}

	void ElementService::Initialize()
	{
		for (int i = 0; i < bunkerDataList.size(); i++)
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();

			bunker_controller->Initialize(bunkerDataList[i]);
			bunkerList.push_back(bunker_controller);
		}
	}

	void ElementService::Update()
	{
		for (int i = 0; i < bunkerList.size(); i++)
		{
			bunkerList[i]->Update();
		}
	}

	void ElementService::Render()
	{
		for (int i = 0; i < bunkerList.size(); i++)
		{
			bunkerList[i]->Render();
		}
	}

	void ElementService::Destroy()
	{
		for (int i = 0; i < bunkerList.size(); i++)
		{
			delete(bunkerList[i]);
		}
	}
}