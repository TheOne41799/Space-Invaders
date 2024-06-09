#pragma once
#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"


namespace Enemy
{
	class EnemyController;


	class EnemyView
	{
    private:
        const float enemySpriteWidth = 60.f;
        const float enemySpriteHeight = 60.f;

        EnemyController* enemyController;
        UI::UIElement::ImageView* enemyImage;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetEnemyTexturePath();

        void Destroy();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();

        const sf::Sprite& GetEnemySprite();
	};
}