#pragma once
#include <chrono>
#include "../GameScenes/SceneManager.h"
#include "../Inputs/InputHandler.h"

class Game {

public:
	Game();
	~Game();
	void InitSceneManager();
	void GameLoop();

private:
	void HandleEvents();
	void Update(const double& elapsedTime);
	void Render();

	SceneManager* _sceneManager;
	bool _isRunning;
};