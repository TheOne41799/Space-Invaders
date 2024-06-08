#pragma once
#include <SFML/Graphics.hpp>
#include "../Collision/ICollider.h"


namespace Enemy
{
	class EnemyModel;
	class EnemyView;

	enum class EnemyType;
	enum class EnemyState;


	class EnemyController : public Collision::ICollider
	{
	protected:
		float verticalMovementSpeed = 30.f;
		float horizontalMovementSpeed = 200.0f;

		float rateOfFire = 3.f;
		float elapsedFireDuration = 0.f;

		EnemyModel* enemyModel;
		EnemyView* enemyView;

		void UpdateFireTimer();
		void ProcessBulletFire();
		virtual void FireBullet() = 0;

		virtual void Move() = 0;

		sf::Vector2f GetRandomInitialPosition();
		//void HandleOutOfBounds();

		virtual void Destroy();

	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		EnemyState GetEnemyState();
		EnemyType GetEnemyType();

		const sf::Sprite& GetColliderSprite() override;
		virtual void OnCollision(ICollider* otherCollider) override;
	};
}
