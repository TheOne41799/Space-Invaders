#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"


namespace Enemy
{
	using namespace Global;


	EnemyController::EnemyController()
	{
		enemyModel = new EnemyModel();
		enemyView = new EnemyView();
	}

	EnemyController::~EnemyController()
	{
		delete(enemyModel);
		delete(enemyView);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyView->Initialize(this);
	}

	void EnemyController::Update()
	{
		enemyView->Update();
	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();
	}

}