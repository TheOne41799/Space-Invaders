#pragma once


namespace Player
{
	class PlayerController;


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

		void IncreaseEnemiesKilled(int val);

		void EnableShield();
		void EnableRapidFire();
		void EnableTrippleLaser();

		void Reset();
	};
}
