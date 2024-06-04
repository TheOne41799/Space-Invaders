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
	};
}
