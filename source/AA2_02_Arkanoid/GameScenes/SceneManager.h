#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <iostream>
#include <map>

#include "../Constants/Constants.h"

#include "../Player/Player.h"

#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

#include "SplashScreenScene.h"
#include "MainMenuScene.h"
#include "RankingScene.h"
#include "GameScene.h"


class SceneManager {

public:
	SceneManager() = default;
	~SceneManager();

	void Init();
	void InitStates();
	void InitSDL();
	void InitWindowAndRenderer();
	void InitFont();
	void InitAudioSDL();

	void InitPlayers();

	void HandleEvents();
	void Update(const double elapsedTime);
	void Render();
	void Release();

	bool IsRunning();

private:
	Scene* _currentScene;
	std::map<Scenes, Scene*> _scenes;
	bool _isSceneFinished;

	SDL_Window* _window;
	SDL_Renderer* _renderer;

	Player* _player1;
	Player* _player2;


	//Vector2D<int> _mousePosition;

	bool _isRunning;
};