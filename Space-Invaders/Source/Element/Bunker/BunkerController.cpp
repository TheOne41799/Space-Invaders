#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerView.h"


namespace Elements
{
	namespace Bunker
	{
		BunkerController::BunkerController()
		{
			bunkerView = new BunkerView();
		}

		BunkerController::~BunkerController() 
		{ 
			delete(bunkerView);
		}

		void BunkerController::Initialize(BunkerData data)
		{
			bunkerData = data;
			bunkerView->Initialize(this);
		}

		void BunkerController::Update()
		{ 
			bunkerView->Update();
		}

		void BunkerController::Render()
		{ 
			bunkerView->Render();
		}

		sf::Vector2f BunkerController::GetBunkerPosition() 
		{ 
			return bunkerData.bunkerPosition;
		}
	}
}



