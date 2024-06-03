#pragma once
#include <SFML/System/Vector2.hpp>


namespace Elements
{
	namespace Bunker
	{
		struct BunkerData
		{
			sf::Vector2f bunkerPosition;

			BunkerData();
			BunkerData(sf::Vector2f position);
		};
	}
}