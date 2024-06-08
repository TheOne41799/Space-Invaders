#pragma once
#include "ImageView.h"
#include <functional>


namespace UI
{
	namespace UIElement
	{
		class ButtonView : public ImageView
		{
		private:
			using CallbackFunction = std::function<void()>;

			CallbackFunction callbackFunction = nullptr;

			void PrintButtonClicked();

		protected:
			sf::String buttonTitle;

			virtual void HandleButtonInteraction();
			virtual bool ClickedButton(sf::Sprite* buttonSprite, sf::Vector2f mousePosition);

		public:
			ButtonView();
			virtual ~ButtonView();

			virtual void Initialize(sf::String title,
									sf::String texturePath,
									float buttonWidth, float buttonHeight,
									sf::Vector2f position);
			virtual void Update() override;
			virtual void Render() override;

			void RegisterCallbackFuntion(CallbackFunction buttonCallback);
		};
	}
}