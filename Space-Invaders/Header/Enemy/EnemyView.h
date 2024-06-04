#pragma once
#include <SFML/Graphics.hpp>


namespace Enemy
{
	class EnemyController;

    enum class EnemyType;
    enum class MovementDirection;
    enum class EnemyState;


	class EnemyView
	{
    private:
        const float enemySpriteWidth = 60.f;
        const float enemySpriteHeight = 60.f;

        EnemyController* enemyController;

        sf::RenderWindow* gameWindow;
        sf::Texture enemyTexture;
        sf::Sprite enemySprite;

        void InitializeEnemySprite(EnemyType type);
        void ScaleEnemySprite();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();
	};
}