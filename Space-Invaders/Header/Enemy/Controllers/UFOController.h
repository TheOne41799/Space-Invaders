#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../Header/Powerups/PowerupConfig.h"


namespace Enemy
{
    namespace Controller
    {
        class UFOController : public EnemyController
        {
        private:

            void Move() override;
            void MoveLeft();
            void MoveRight();

            void FireBullet() override;

            Powerup::PowerupType GetRandomPowerupType();

        public:
            UFOController(EnemyType type);
            ~UFOController();

            void Initialize() override;
            void OnCollision(ICollider* otherCollider) override;
        };
    }
}
