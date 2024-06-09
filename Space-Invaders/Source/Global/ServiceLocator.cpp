#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"


namespace Global
{
	using namespace Graphics;
	using namespace Time;
	using namespace Event;
	using namespace Player;
	using namespace UI;
	using namespace Enemy;
	using namespace Main;
	using namespace Gameplay;
	using namespace Elements;
	using namespace Sound;
	using namespace Bullet;
	using namespace Powerup;
	using namespace Collision;
	using namespace Animation;


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
		collisionService = nullptr;
		animationService = nullptr;

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
		bulletService = new BulletService();
		powerupService = new PowerupService();
		collisionService = new CollisionService();
		soundService = new SoundService();
		animationService = new AnimationService();
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
		delete(collisionService);
		delete(animationService);
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
		collisionService->Initialize();
		animationService->Initialize();
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
			elementService->Update();
			bulletService->Update();			
			powerupService->Update();
			collisionService->Update();
			animationService->Update();
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
			elementService->Render();
			bulletService->Render();
			powerupService->Render();
			animationService->Render();
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

	UIService* ServiceLocator::GetUIService()
	{
		return uiService;
	}

	EnemyService* ServiceLocator::GetEnemyService()
	{
		return enemyService;
	}

	GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}

	ElementService* ServiceLocator::GetElementService()
	{
		return elementService;
	}

	SoundService* ServiceLocator::GetSoundService()
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

	CollisionService* ServiceLocator::GetCollisionService()
	{
		return collisionService;
	}

	AnimationService* ServiceLocator::GetAnimationService()
	{
		return animationService;
	}
}


