#include "AudioHandler.h"


AudioHandler* AudioHandler::_instance = nullptr;

AudioHandler::AudioHandler()
	: _audioIsOn(true), _musicVolume(MAX_VOLUME / 4)
{}

AudioHandler* AudioHandler::GetInstance()
{
	if (_instance == nullptr) {
		_instance = new AudioHandler();
	}
	return _instance;
}


void AudioHandler::AudioSwitch()
{
	if (_audioIsOn) {
		_audioIsOn = false;
		MuteAudio();
	}
	else {
		_audioIsOn = true;
		UnmuteAudio();
	}
}

void AudioHandler::MuteAudio()
{
	Mix_PauseMusic();
}

void AudioHandler::UnmuteAudio()
{
	Mix_ResumeMusic();
}

void AudioHandler::SetMusicVolume(const int& musicVolume)
{
	if (musicVolume < MIN_VOLUME) {
		_musicVolume = MIN_VOLUME;
	}
	else if (musicVolume < MAX_VOLUME) {
		_musicVolume = MAX_VOLUME;
	}
	else {
		_musicVolume = musicVolume;
	}

	Mix_VolumeMusic(_musicVolume);
}



Mix_Chunk* AudioHandler::LoadAudioSFX(const char* path)
{
	Mix_Chunk* mixChunk = Mix_LoadWAV(path);
	return mixChunk;
}

Mix_Music* AudioHandler::LoadMusic(const char* path)
{
	Mix_Music* mixMusic = Mix_LoadMUS(path);
	return mixMusic;
}



void AudioHandler::PlayAudioSFX(Mix_Chunk* mixChunk)
{
	int channelAudio = Mix_PlayChannel(-1, mixChunk, 0); // Reproduce audio on first available channel (-1), returns -1 if no available channels

	if (channelAudio == -1) {
		SDL_GetError();
	}
}

void AudioHandler::PlayMusic(Mix_Music* mixMusic)
{
	int channelAudio = Mix_PlayMusic(mixMusic, -1);

	if (channelAudio == -1) {
		SDL_GetError();
	}

	Mix_VolumeMusic(_musicVolume);

	if (_audioIsOn) {
		UnmuteAudio();
	}
	else {
		MuteAudio();
	}

}



void AudioHandler::DeleteAudioSFX(Mix_Chunk* mixChunk)
{
	Mix_HaltMusic();
	Mix_FreeChunk(mixChunk);
}


void AudioHandler::DeleteMusic(Mix_Music* mixMusic)
{
	Mix_HaltMusic();
	//SDL_Delay(100);
	Mix_FreeMusic(mixMusic);
}