#pragma once
#include "../../Header/Powerups/PowerupController.h"


namespace Powerup
{
    namespace Controller
    {
        class TrippleLaserController : public PowerupController
        {
        protected:
            void ApplyPowerup() override;

        public:
            TrippleLaserController(PowerupType type);
            virtual ~TrippleLaserController();

            //void OnCollected() override;
        };
    }
}
