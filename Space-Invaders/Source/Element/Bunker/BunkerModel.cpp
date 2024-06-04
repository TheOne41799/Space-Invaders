#include "../../Header/Element/Bunker/BunkerModel.h"


namespace Elements
{
	namespace Bunker
	{
		BunkerData::BunkerData()
		{
		}

		BunkerData::BunkerData(sf::Vector2f position)
		{
			this->bunkerPosition = position;
		}
	}
}