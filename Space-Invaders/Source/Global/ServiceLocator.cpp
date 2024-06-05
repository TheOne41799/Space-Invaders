#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"


namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Player;
	using namespace Time;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Elements;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;


	ServiceLocator::ServiceLocator()
	{
		graphicService = nullptr;
		timeService = nullptr;
		eventService = nullptr;
		playerService = nullptr;
		uiService = nullptr;
		enemyService = nullptr;
		gameplayService = nullptr;
		elementService = nullptr;
		soundService = nullptr;
		bulletService = nullptr;
		powerupService = nullptr;

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
		uiService = new UIService();
		enemyService = new EnemyService();
		gameplayService = new GameplayService();
		elementService = new ElementService();
		soundService = new SoundService();
		bulletService = new BulletService();
		powerupService = new PowerupService();
	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		delete(timeService);
		delete(eventService);
		delete(playerService);
		delete(uiService);
		delete(enemyService);
		delete(gameplayService);
		delete(elementService);
		delete(soundService);
		delete(bulletService);
		delete(powerupService);
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
		gameplayService->Initialize();
		playerService->Initialize();
		uiService->Initialize();
		enemyService->Initialize();
		elementService->Initialize();
		soundService->Initialize();
		bulletService->Initialize();
		powerupService->Initialize();
	}

	void ServiceLocator::Update()
	{
		graphicService->Update();
		timeService->Update();
		eventService->Update();

		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Update();
			playerService->Update();
			enemyService->Update();
			bulletService->Update();
			elementService->Update();
			powerupService->Update();
		}

		uiService->Update();
	}

	void ServiceLocator::Render()
	{
		graphicService->Render();

		if (GameService::GetGameState() == GameState::GAMEPLAY)
		{
			gameplayService->Render();
			playerService->Render();
			enemyService->Render();
			bulletService->Render();
			elementService->Render();
			powerupService->Render();
		}

		uiService->Render();
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

	UI::UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}

	Enemy::EnemyService* ServiceLocator::GetEnemyService()
	{
		return enemyService;
	}

	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}

	Elements::ElementService* ServiceLocator::GetElementService()
	{
		return elementService;
	}

	Sound::SoundService* ServiceLocator::GetSoundService()
	{
		return soundService;
	}

	BulletService* ServiceLocator::GetBulletService()
	{ 
		return bulletService;
	}

	PowerupService* ServiceLocator::GetPowerupService()
	{
		return powerupService;
	}

	void ServiceLocator::DeleteServiceLocator()
	{
		delete(this);
	}
}


