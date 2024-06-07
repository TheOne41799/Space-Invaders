#pragma once
#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"


namespace Bullet
{
    class BulletController;

    //enum class BulletType;


    class BulletView
    {
    private:
        const float bulletSpriteWidth = 18.f;
        const float bulletSpriteHeight = 18.f;

        /*sf::RenderWindow* gameWindow;
        sf::Texture bulletTexture;
        sf::Sprite bulletSprite;*/

        BulletController* bulletController;
        UI::UIElement::ImageView* bulletImage;

        /*void InitializeImage(BulletType type);
        void ScaleImage();*/

        void CreateUIElements();
        void InitializeImage();
        sf::String GetBulletTexturePath();

        void Destroy();

    public:
        BulletView();
        ~BulletView();

        void Initialize(BulletController* controller);
        void Update();
        void Render();
    };
}


