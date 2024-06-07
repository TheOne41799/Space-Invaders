#pragma once
#include "../../Header/Powerups/PowerupController.h"


namespace Powerup
{
    namespace Controller
    {
        class RapidFireController : public PowerupController
        {
        protected:
            void ApplyPowerup() override;

        public:
            RapidFireController(PowerupType type);
            virtual ~RapidFireController();

            //void OnCollected() override;
        };
    }
}
