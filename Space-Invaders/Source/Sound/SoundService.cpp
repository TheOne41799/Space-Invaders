#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"


namespace Sound
{
	using namespace Global;


	void SoundService::Initialize()
	{
		LoadBackgroundMusicFromFile();
		LoadSoundFromFile();
	}

	void SoundService::LoadBackgroundMusicFromFile()
	{
		if (!backgroundMusic.openFromFile(Config::backgroundMusicPath))
		{
			printf("Error loading background music file");
		}
	}

	void SoundService::LoadSoundFromFile()
	{
		if (!bufferButtonClick.loadFromFile(Config::buttonClickSoundPath))
		{
			printf("Error loading sound file");
		}
		if (!bufferBulletFire.loadFromFile(Config::bulletFireSoundPath))
		{
			printf("Error loading sound file");
		}
		if (!bufferPowerupEnabled.loadFromFile(Config::powerupEnabledSoundPath))
		{
			printf("Error loading sound file");
		}
		if (!bufferPowerupDisabled.loadFromFile(Config::powerupDisabledSoundPath))
		{
			printf("Error loading sound file");
		}
		if (!bufferExplosionSound.loadFromFile(Config::explosionSoundPath))
		{
			printf("Error loading sound file");
		}
	}

	void SoundService::PlaySound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			soundEffect.setBuffer(bufferButtonClick);
			break;
		case SoundType::BULLET_FIRE:
			soundEffect.setBuffer(bufferBulletFire);
			soundEffect.play();
			break;
		case SoundType::POWERUP_ENABLED:
			powerupSoundEffect.setBuffer(bufferPowerupEnabled);
			powerupSoundEffect.play();
			break;
		case SoundType::POWERUP_DISABLED:
			powerupSoundEffect.setBuffer(bufferPowerupDisabled);
			powerupSoundEffect.play();
			break;
		case SoundType::EXPLOSION:
			explosionSoundEffect.setBuffer(bufferExplosionSound);
			explosionSoundEffect.play();
			break;
		default:
			printf("Invalid sound type");
			return;
		}

		soundEffect.play();
	}

	void SoundService::PlayBackgroundMusic()
	{
		backgroundMusic.setLoop(true);
		backgroundMusic.setVolume(backgroundMusicVolume);
		backgroundMusic.play();
	}
}


