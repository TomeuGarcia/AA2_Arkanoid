#pragma once
#include <chrono>
#include "../GameScenes/SceneManager.h"
#include "GameInputs.h"

class Game {

public:
	Game();
	~Game();
	void InitSceneManager();
	void GameLoop();

private:
	SceneManager* _sceneManager;
	bool _isRunning;
};