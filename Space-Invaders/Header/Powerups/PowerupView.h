#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"


namespace Powerup
{
    class PowerupController;

    enum class PowerupType;


    class PowerupView
    {
    private:
        const float powerupSpriteWidth = 30.f;
        const float powerupSpriteHeight = 30.f;

        /*sf::RenderWindow* gameWindow;
        sf::Texture powerupTexture;
        sf::Sprite powerupSprite;*/

        PowerupController* powerupController;
        UI::UIElement::ImageView* powerupImage;

        //void InitializeImage(PowerupType);
        //void ScaleImage();

        void CreateUIElements();
        void InitializeImage();
        sf::String GetPowerupTexturePath();

        void Destroy();

    public:
        PowerupView();
        ~PowerupView();

        void Initialize(PowerupController* controller);
        void Update();
        void Render();
    };
}
