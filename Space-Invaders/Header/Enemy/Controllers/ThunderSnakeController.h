#pragma once
#include "../../header/Enemy/EnemyController.h"
#include "../../header/Enemy/EnemyConfig.h"


namespace Enemy
{
    namespace Controller
    {
        class ThunderSnakeController : public EnemyController
        {
        private:
            const float thunderSnakeHorizontalMovementSpeed = 120.f;

            void Move() override;
            void MoveLeft();
            void MoveRight();
            void MoveDiagonalLeft();
            void MoveDiagonalRight();

            void FireBullet() override;
            void Destroy() override;

            MovementDirection GetInitialMovementDirection();

        public:
            ThunderSnakeController(EnemyType type);
            ~ThunderSnakeController();

            void Initialize() override;
        };
    }
}
