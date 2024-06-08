#include "../../Header/Element/ElementService.h"
#include "../../header/Collision/ICollider.h"
#include "../../header/Global/ServiceLocator.h"


namespace Elements
{	
	using namespace Global;
	using namespace Collision;


	ElementService::ElementService()
	{
	}

	ElementService::~ElementService()
	{
		Destroy();
	}

	void ElementService::Initialize()
	{
		/*for (int i = 0; i < bunkerDataList.size(); i++)
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();

			bunker_controller->Initialize(bunkerDataList[i]);
			bunkerList.push_back(bunker_controller);
		}*/

		SpawnBunkers();
	}

	void ElementService::Update()
	{
		for (int i = 0; i < bunkerList.size(); i++)
		{
			bunkerList[i]->Update();
		}

		DestroyFlaggedBunkers();
	}

	void ElementService::Render()
	{
		for (int i = 0; i < bunkerList.size(); i++)
		{
			bunkerList[i]->Render();
		}
	}

	void ElementService::SpawnBunkers()
	{
		for (int i = 0; i < bunkerDataList.size(); i++)
		{
			Bunker::BunkerController* bunker_controller = new Bunker::BunkerController();

			bunker_controller->Initialize(bunkerDataList[i]);
			bunkerList.push_back(bunker_controller);

			ServiceLocator::GetInstance()->GetCollisionService()
										 ->AddCollider(dynamic_cast<ICollider*>(bunker_controller));
		}
	}

	void ElementService::DestroyBunker(Bunker::BunkerController* bunker_controller)
	{
		flaggedBunkerList.push_back(bunker_controller);
		bunkerList.erase(std::remove(bunkerList.begin(), bunkerList.end(), bunker_controller), bunkerList.end());
	}

	void ElementService::DestroyFlaggedBunkers()
	{
		for (int i = 0; i < flaggedBunkerList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
										 ->RemoveCollider(dynamic_cast<ICollider*>(flaggedBunkerList[i]));
			delete (flaggedBunkerList[i]);
		}
		flaggedBunkerList.clear();
	}

	void ElementService::Destroy()
	{
		/*for (int i = 0; i < bunkerList.size(); i++)
		{
			delete(bunkerList[i]);
		}*/

		for (int i = 0; i < bunkerList.size(); i++)
		{
			ServiceLocator::GetInstance()->GetCollisionService()
										 ->RemoveCollider(dynamic_cast<ICollider*>(bunkerList[i]));
			delete(bunkerList[i]);
		}

		bunkerList.clear();
	}

	void ElementService::Reset()
	{
		Destroy();
		SpawnBunkers();
	}
}