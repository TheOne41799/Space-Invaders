#pragma once
#include "../EnemyController.h"


namespace Enemy
{
	namespace Controller
	{
		class SubZeroController : public EnemyController
		{
		private:
			float verticalMovementSpeed = 100.f;

			void Move() override;
			void MoveDown();

		public:
			SubZeroController(EnemyType type);
			~SubZeroController();

			void Initialize() override;
		};
	}
}
