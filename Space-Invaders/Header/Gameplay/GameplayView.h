#pragma once
#include <SFML/Graphics.hpp>
#include "../../header/UI/UIElement/ImageView.h"

namespace Gameplay
{
    class GameplayController;


    class GameplayView
    {
    private:

        sf::RenderWindow* gameWindow;
        sf::Texture backgroundTexture;
        sf::Sprite backgroundSprite;
        const float background_alpha = 150.f;

        /*void InitializeBackgroundSprite();
        void ScaleBackgroundSprite();*/

        GameplayController* gameplayController;
        UI::UIElement::ImageView* backgroundImage;

        void InitializeBackgroundImage();

    public:
        GameplayView();
        ~GameplayView();

        void Initialize();
        void Update();
        void Render();
    };
}
