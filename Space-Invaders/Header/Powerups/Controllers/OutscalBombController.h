#pragma once
#include "../../Header/Powerups/PowerupController.h"


namespace Powerup
{
    namespace Controller
    {
        class OutscalBombController : public PowerupController
        {
        protected:
            void ApplyPowerup() override;

        public:
            OutscalBombController(PowerupType type);
            virtual ~OutscalBombController();

            //void OnCollected() override;
        };
    }
}
