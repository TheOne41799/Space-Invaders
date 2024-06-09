#pragma once
#include <vector>


namespace Collision
{
	class ICollider;


	class CollisionService
	{
	private:
		std::vector<ICollider*> colliderList;

		void ProcessCollision();
		void DoCollision(int index_i, int index_j);
		bool HasCollisionOccurred(int index_i, int index_j);
		bool AreActiveColliders(int index_i, int index_j);

	public:
		CollisionService();
		~CollisionService();

		void Initialize();
		void Update();

		void AddCollider(ICollider* collider);
		void RemoveCollider(ICollider* collider);
	};
}
