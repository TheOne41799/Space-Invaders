#pragma once
#include "../../Powerups/PowerupController.h"


namespace Powerup
{
    namespace Controller
    {
        class ShieldController : public PowerupController
        {
        protected:
            void ApplyPowerup() override;

        public:
            ShieldController(PowerupType type);
            virtual ~ShieldController();

            //void OnCollected() override;
        };
    }
}