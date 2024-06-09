#pragma once
#include "../EnemyController.h"


namespace Enemy
{
	namespace Controller
	{
		class SubZeroController : public EnemyController
		{
		private:
			const float subZeroRateOfFire = 2.f;
			float subZeroVerticalMovementSpeed = 100.f;

			void Move() override;
			void MoveDown();

			void FireBullet() override;
			void Destroy() override;

		public:
			SubZeroController(EnemyType type);
			~SubZeroController();

			void Initialize() override;
		};
	}
}
