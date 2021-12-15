#pragma once
#include <chrono>
#include "../GameScenes/SceneManager.h"

class Game {

public:
	Game();
	~Game();
	void InitSceneManager();
	void GameLoop();

private:
	SceneManager* _sceneManager;
};