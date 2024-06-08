#pragma once


namespace Player
{
	class PlayerController; //This led to a small error - chapter - Using Forward Declarations


	class PlayerService
	{
	private:
		PlayerController* playerController;

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		//void IncreaseScore(int val);
		//void DecreaseScore(int val);
		void IncreaseEnemiesKilled(int val);

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		void Reset();
	};
}
