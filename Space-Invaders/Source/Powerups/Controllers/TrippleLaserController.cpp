#include "../../Header/Powerups/Controllers/TrippleLaserController.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Powerup
{
    namespace Controller
    {
        using namespace Global;


        TrippleLaserController::TrippleLaserController(PowerupType type) : PowerupController(type) {}

        TrippleLaserController::~TrippleLaserController() {}

        //void TrippleLaserController::OnCollected() {};

        void TrippleLaserController::ApplyPowerup()
        {
            ServiceLocator::GetInstance()->GetPlayerService()->EnableTrippleLaser();
        }
    }
}