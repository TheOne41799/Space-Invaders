#pragma once
#include "../EnemyController.h"


namespace Enemy
{
	namespace Controller
	{
		class ZapperController: public EnemyController
		{
        private:
            float verticalTravelDistance = 100.f;

            void Move() override;
            void MoveLeft();
            void MoveRight();
            void MoveDown();

        public:
            ZapperController(EnemyType type);
            ~ZapperController();

            void Initialize() override;
		};
	}
}