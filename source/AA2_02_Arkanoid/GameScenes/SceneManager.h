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

	Scene* _currentScene;
	std::map<Scenes, Scene*> _scenes;
	bool _isSceneFinished;

	SDL_Renderer* _renderer;

	bool* _isRunning;
};