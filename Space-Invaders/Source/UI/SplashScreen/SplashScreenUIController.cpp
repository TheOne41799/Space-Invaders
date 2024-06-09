#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"


namespace UI
{
    namespace SplashScreen
    {
        using namespace Main;
        using namespace Graphics;
        using namespace Global;
        using namespace UIElement;
        using namespace Sound;


        SplashScreenUIController::SplashScreenUIController()
        {
            outscalLogoView = new ImageView();
        }

        SplashScreenUIController::~SplashScreenUIController()
        {
            delete (outscalLogoView);
        }

        void SplashScreenUIController::Initialize()
        {
            InitializeOutscalLogo();
        }

        void SplashScreenUIController::Update()
        {
            UpdateTimer();
            ShowMainMenu();
        }

        void SplashScreenUIController::Render()
        {
            outscalLogoView->Render();
        }

        void SplashScreenUIController::InitializeOutscalLogo()
        {
            sf::Vector2f position = GetLogoPosition();
            outscalLogoView->Initialize(Config::outscalLogoTexturePath, logoWidth, logoHeight, position);

        }

        void SplashScreenUIController::ShowMainMenu()
        {
            if (elapsedDuration >= splashScreenDuration)
            {
                ServiceLocator::GetInstance()->GetSoundService()->PlayBackgroundMusic();
                GameService::SetGameState(GameState::MAIN_MENU);
            }

        }

        void SplashScreenUIController::UpdateTimer()
        {
            elapsedDuration += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
        }

        sf::Vector2f SplashScreenUIController::GetLogoPosition()
        {
            sf::RenderWindow* game_window = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();

            float xPosition = (game_window->getSize().x - logoWidth) / 2.0f;
            float yPosition = (game_window->getSize().y - logoHeight) / 2.0f;

            return sf::Vector2f(xPosition, yPosition);
        }

        void SplashScreenUIController::Show()
        {

        }
    }
}