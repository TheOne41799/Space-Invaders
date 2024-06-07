#include "../../Header/Powerups/Controllers/RapidFireController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Powerup
{
    namespace Controller
    {
        using namespace Global;


        RapidFireController::RapidFireController(PowerupType type) : PowerupController(type) {}

        RapidFireController::~RapidFireController() {}

        //void RapidFireController::OnCollected() {};

        void RapidFireController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetPlayerService()->EnableRapidFire();
        }
    }
}