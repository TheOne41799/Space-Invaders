#include "../../Header/Powerups/Controllers/ShieldController.h"
#include "../../header/Global/ServiceLocator.h"


namespace Powerup
{
    namespace Controller
    {
        using namespace Global;


        ShieldController::ShieldController(PowerupType type) : PowerupController(type) {}

        ShieldController::~ShieldController() {}

        void ShieldController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetPlayerService()->EnableShield();
        }
    }
}