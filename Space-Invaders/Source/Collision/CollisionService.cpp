#include "../../Header/Collision/CollisionService.h"
#include "../../Header/Collision/ICollider.h"


namespace Collision
{
	CollisionService::CollisionService() { }

	CollisionService::~CollisionService() { }

	void CollisionService::Initialize() { }

	void CollisionService::Update()
	{
		ProcessCollision();
	}

	void CollisionService::ProcessCollision()
	{
		for (int i = 0; i < colliderList.size(); i++)
		{
			for (int j = i + 1; j < colliderList.size(); j++)
			{
				DoCollision(i, j);
			}
		}
	}

	void CollisionService::DoCollision(int index_i, int index_j)
	{
		if (colliderList[index_i]->GetCollisionState() == CollisionState::DISABLED ||
			colliderList[index_j]->GetCollisionState() == CollisionState::DISABLED)
		{
			return;
		}

		if (HasCollisionOccurred(index_i, index_j))
		{
			if (AreActiveColliders(index_i, index_j))
			{
				colliderList[index_i]->OnCollision(colliderList[index_j]);
			}

			if (AreActiveColliders(index_i, index_j))
			{
				colliderList[index_j]->OnCollision(colliderList[index_i]);
			}
		}
	}

	bool CollisionService::HasCollisionOccurred(int index_i, int index_j)
	{
		const sf::Sprite& collider_one_sprite = colliderList[index_i]->GetColliderSprite();
		const sf::Sprite& collider_two_sprite = colliderList[index_j]->GetColliderSprite();

		return collider_one_sprite.getGlobalBounds().intersects(collider_two_sprite.getGlobalBounds());
	}

	bool CollisionService::AreActiveColliders(int index_i, int index_j)
	{
		return (index_i < colliderList.size() && index_j < colliderList.size() &&
				colliderList[index_i] != nullptr && colliderList[index_j] != nullptr);
	}

	void CollisionService::AddCollider(ICollider* collider)
	{
		colliderList.push_back(collider);
	}

	void CollisionService::RemoveCollider(ICollider* collider)
	{
		colliderList.erase(std::remove(colliderList.begin(), colliderList.end(), collider), colliderList.end());
	}
}