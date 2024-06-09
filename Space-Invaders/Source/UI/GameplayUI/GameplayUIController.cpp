#include "../../Header/UI/GameplayUI/GameplayUIController.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Player/PlayerModel.h"


namespace UI
{
    namespace GameplayUI
    {
        using namespace Main;
        using namespace Sound;
        using namespace Global;
        using namespace Player;
        using namespace UI::UIElement;


        GameplayUIController::GameplayUIController() { CreateUIElements(); }

        GameplayUIController::~GameplayUIController() { Destroy(); }

        void GameplayUIController::Initialize()
        {
            InitializeImage();
            InitializeText();
        }

        void GameplayUIController::CreateUIElements()
        {
            playerImage = new ImageView();

            enemiesKilledText = new TextView();
        }

        void GameplayUIController::InitializeImage()
        {
            playerImage->Initialize(Config::playerTexturePath, playerSpriteWidth, playerSpriteHeight,
                                    sf::Vector2f(0, 0));
        }

        void GameplayUIController::InitializeText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  0";

            enemiesKilledText->Initialize(enemies_killed_string,
                                          sf::Vector2f(enemiesKilledTextXPosition, textYPosition),
                                          FontType::BUBBLE_BOBBLE, fontSize, textColor);
        }

        void GameplayUIController::Update()
        {

            UpdateEnemiesKilledText();
        }

        void GameplayUIController::Render()
        {

            enemiesKilledText->Render();
            DrawPlayerLives();
        }

        void GameplayUIController::Show() { }

        void GameplayUIController::UpdateEnemiesKilledText()
        {
            sf::String enemies_killed_string = "Enemies Killed  :  " + std::to_string(PlayerModel::enemiesKilled);
            enemiesKilledText->SetText(enemies_killed_string);
        }

        void GameplayUIController::DrawPlayerLives()
        {
            sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            for (int i = 0; i < PlayerModel::playerLives; i++)
            {
                playerImage->SetPosition(sf::Vector2f(playerLivesXOffset - (i * playerLivesSpacing),
                                                      playerLivesYOffset));
                playerImage->Render();
            }
        }

        void GameplayUIController::Destroy()
        {
            delete(playerImage);

            delete(enemiesKilledText);
        }
    }
}