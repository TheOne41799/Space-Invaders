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
        //const sf::String enemyTexturePath = "assets/textures/zapper.png";

        const sf::String subZeroTexturePath = "assets/textures/subzero.png";
        const sf::String zapperTexturePath = "assets/textures/zapper.png";
        const sf::String thunderSnakeTexturePath = "assets/textures/thunder_snake.png";

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