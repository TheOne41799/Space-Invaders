#include "../../Header/Element/Bunker/BunkerController.h"
#include "../../Header/Element/Bunker/BunkerView.h"
#include "../../../header/Bullet/BulletController.h"
#include "../../../header/Entity/Entity.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../../header/Bullet/BulletConfig.h"



namespace Elements
{
	namespace Bunker
	{
		using namespace Bullet;
		using namespace Entity;
		using namespace Global;


		BunkerController::BunkerController()
		{
			bunkerView = new BunkerView();
		}

		BunkerController::~BunkerController() 
		{ 
			delete(bunkerView);
		}

		void BunkerController::Initialize(BunkerData data)
		{
			bunkerData = data;
			bunkerView->Initialize(this);
		}

		void BunkerController::Update()
		{ 
			bunkerView->Update();
		}

		void BunkerController::Render()
		{ 
			bunkerView->Render();
		}

		const sf::Sprite& BunkerController::GetColliderSprite()
		{
			return bunkerView->GetBunkerSprite();
		}

		void BunkerController::OnCollision(ICollider* other_collider)
		{
			BulletController* bullet_controller = dynamic_cast<BulletController*>(other_collider);

			if (bullet_controller && bullet_controller->GetBulletType() == BulletType::TORPEDOE)
			{
				ServiceLocator::GetInstance()->GetElementService()->DestroyBunker(this);
			}
		}

		sf::Vector2f BunkerController::GetBunkerPosition() 
		{ 
			return bunkerData.bunkerPosition;
		}
	}
}



