#pragma once
#include <SFML/Graphics.hpp>
#include "../UI/UIElement/ImageView.h"


namespace Bullet
{
    class BulletController;


    class BulletView
    {
    private:
        const float bulletSpriteWidth = 18.f;
        const float bulletSpriteHeight = 18.f;

        BulletController* bulletController;
        UI::UIElement::ImageView* bulletImage;

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

        const sf::Sprite& GetBulletSprite();
    };
}


