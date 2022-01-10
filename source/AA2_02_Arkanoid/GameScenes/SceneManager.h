#pragma once
#include <iostream>
#include <map>

#include "../Constants/Constants.h"

#include "../Inputs/InputHandler.h"
#include "../Inputs/Keyboard.h"

#include "SplashScreenScene.h"
#include "MainMenuScene.h"
#include "RankingScene.h"
#include "GameScene.h"


class SceneManager {

public:
	SceneManager(bool* isRunning, SDL_Renderer* renderer);
	~SceneManager();

	void Update(const double& elapsedTime);
	void Render();
	
	bool IsRunning();

private:
	void InitScenes();
	void SetNewCurrentScene(const Scenes& newCurrentScene);

	Scene* _currentScene;
	bool _isSceneFinished;

	SDL_Renderer* _renderer;

	bool* _isRunning;
};