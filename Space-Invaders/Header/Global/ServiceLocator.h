#pragma once
#include "../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../UI/UIService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"
#include "../Enemy/EnemyService.h"
#include "../Gameplay/GameplayService.h"
#include "../Element/ElementService.h"
#include "../Bullet/BulletService.h"
#include "../Powerups/PowerupService.h"
#include "../Sound/SoundService.h"
#include "../Collision/CollisionService.h"
#include "../AnimationSystem/AnimationService.h"


namespace Global
{
	class ServiceLocator
	{
	private:

		Event::EventService* eventService;
		Graphics::GraphicService* graphicService;
		UI::UIService* uiService;
		Time::TimeService* timeService;
		Gameplay::GameplayService* gameplayService;
		Player::PlayerService* playerService;
		Enemy::EnemyService* enemyService;
		Elements::ElementService* elementService;
		Bullet::BulletService* bulletService;
		Powerup::PowerupService* powerupService;
		Sound::SoundService* soundService;
		Collision::CollisionService* collisionService;
		Animation::AnimationService* animationService;

		ServiceLocator();
		~ServiceLocator();

		void CreateServices();
		void ClearAllServices();

	public:
		static ServiceLocator* GetInstance();

		void Initialize();
		void Update();
		void Render();

		Event::EventService* GetEventService();
		Graphics::GraphicService* GetGraphicService();
		UI::UIService* GetUIService();
		Time::TimeService* GetTimeService();
		Gameplay::GameplayService* GetGameplayService();
		Player::PlayerService* GetPlayerService();
		Enemy::EnemyService* GetEnemyService();
		Elements::ElementService* GetElementService();
		Bullet::BulletService* GetBulletService();
		Powerup::PowerupService* GetPowerupService();
		Sound::SoundService* GetSoundService();
		Collision::CollisionService* GetCollisionService();
		Animation::AnimationService* GetAnimationService();
	};
}
