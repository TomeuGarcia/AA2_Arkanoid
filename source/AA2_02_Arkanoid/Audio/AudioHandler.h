#pragma once
#include <SDL.h>
#include <SDL_mixer.h>
#include <vector>

#define MAX_VOLUME 128
#define MIN_VOLUME 0


class AudioHandler {

private:
	AudioHandler();

public:
	static AudioHandler* GetInstance();

	void AudioSwitch();
	void MuteAudio();
	void UnmuteAudio();
	void SetMusicVolume(const int& musicVolume);

	Mix_Chunk* LoadAudioSFX(const char* path);
	Mix_Music* LoadMusic(const char* path);

	void PlayAudioSFX(Mix_Chunk* mixChunk);
	void PlayMusic(Mix_Music* mixMusic);

	void DeleteAudioSFX(Mix_Chunk* mixChunk);
	void DeleteMusic(Mix_Music* mixMusic);


private:
	static AudioHandler* _instance;
	bool _audioIsOn;
	int _musicVolume;
};