#pragma once
#include "../Graphics/GraphicService.h"
#include "../Event/EventService.h"
#include "../Player/PlayerService.h"
#include "../Time/TimeService.h"
#include "../UI/UIService.h"


namespace Global
{
	class ServiceLocator
	{
	private:

		Graphics::GraphicService* graphicService;
		Event::EventService* eventService;
		Player::PlayerService* playerService;
		Time::TimeService* timeService;
		UI::UIService* uiService;

		ServiceLocator();

		~ServiceLocator();

		void CreateServices();

		void ClearAllServices();

	public:
		static ServiceLocator* GetInstance();

		void Initialize();

		void Update();

		void Render();

		Graphics::GraphicService* GetGraphicService();
		Event::EventService* GetEventService();
		Player::PlayerService* GetPlayerService();
		Time::TimeService* GetTimeService();
		UI::UIService* GetUIService();

	};
}