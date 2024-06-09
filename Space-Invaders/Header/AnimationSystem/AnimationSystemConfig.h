#pragma once
#include <SFML/Graphics.hpp>


namespace Animation
{
    struct AnimationSystemConfig
    {
        sf::String animationTexturePath;

        float spriteSheetWidth;
        float spriteSheetHeight;

        float tileWidth;
        float tileHeight;

        int numberOfAnimationFrames;
        float frameDuration;

        AnimationSystemConfig() = default;

        AnimationSystemConfig(sf::String texturePath, float spriteWidth, float spriteHeight,
                              float tWidth, float tHeight, int frames, float duration) :
            animationTexturePath(texturePath),
            spriteSheetWidth(spriteWidth),
            spriteSheetHeight(spriteHeight),
            tileWidth(tWidth),
            tileHeight(tHeight),
            numberOfAnimationFrames(frames),
            frameDuration(duration) {}
    };
}