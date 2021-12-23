#pragma once
#include <chrono>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include "../GameScenes/SceneManager.h"
#include "../Inputs/InputHandler.h"

class Game {

public:
	Game();
	~Game();
	void GameLoop();

private:
	void InitSDL();
	void InitWindowAndRenderer();
	void InitFont();
	void InitAudioSDL();

	void InitSceneManager();

	void HandleEvents();
	void Update(const double& elapsedTime);
	void Render();
	void Release();


	SDL_Window* _window;
	SDL_Renderer* _renderer;
	SceneManager* _sceneManager;
	bool _isRunning;
};