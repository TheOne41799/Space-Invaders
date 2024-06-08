#pragma once
#include "SFML/Audio.hpp"


namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		BULLET_FIRE,
		EXPLOSION,
		POWERUP_ENABLED,
		POWERUP_DISABLED,
	};


	class SoundService
	{
	private:
		const int backgroundMusicVolume = 30;

		sf::Music backgroundMusic;
		sf::Sound soundEffect;

		sf::Sound powerupSoundEffect;

		sf::SoundBuffer bufferButtonClick;
		sf::SoundBuffer bufferBulletFire;

		sf::SoundBuffer bufferPowerupEnabled;
		sf::SoundBuffer bufferPowerupDisabled;

		void LoadBackgroundMusicFromFile();
		void LoadSoundFromFile();

	public:
		void Initialize();

		void PlaySound(SoundType soundType);
		void PlayBackgroundMusic();
	};
}