#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "Bunker/BunkerController.h"
#include "Bunker/BunkerModel.h"


namespace Elements
{
	class BunkerController;


	class ElementService
	{
	private:
		const std::vector<Bunker::BunkerData> bunkerDataList = { Bunker::BunkerData(sf::Vector2f(130.f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(430.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(730.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1130.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1430.0f, 800.f)),
																Bunker::BunkerData(sf::Vector2f(1730.0f, 800.f))};

		std::vector<Bunker::BunkerController*> bunkerList;

		void Destroy();

	public:
		ElementService();
		~ElementService();

		void Initialize();
		void Update();
		void Render();

		void Reset();
	};
}
