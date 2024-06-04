#pragma once


namespace Bullet
{
	class BulletService
	{
	private:

	public:
		BulletService();
		~BulletService();

		void Initialize();
		void Update();
		void Render();
	};
}
