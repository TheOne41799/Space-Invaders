#include "../../header/Gameplay/GameplayController.h"
#include "../../header/Gameplay/GameplayView.h"


namespace Gameplay
{
	GameplayController::GameplayController()
	{ 
		gameplayView = new GameplayView();
	}

	GameplayController::~GameplayController()
	{ 
		delete (gameplayView);
	}

	void GameplayController::Initialize()
	{
		gameplayView->Initialize();
	}

	void GameplayController::Update() 
	{ 
		gameplayView->Update();
	}

	void GameplayController::Render()
	{ 
		gameplayView->Render();
	}
}