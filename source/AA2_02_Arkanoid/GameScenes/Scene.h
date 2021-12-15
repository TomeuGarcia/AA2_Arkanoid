#pragma once
#include <iostream>
#include "../Inputs/InputHandler.h"
#include "../Player/Player.h"

enum class Scenes{NONE, SPLASH_SCREEN, MAIN_MENU, RANKING, GAME, QUIT};

class Scene {

public:
	Scene(SDL_Renderer* renderer) : _nextScene(Scenes::NONE), _renderer(renderer) {}
	virtual ~Scene() = default;

	void Start() {
		_nextScene = Scenes::NONE;
		DoStart();
	}
	virtual void HandleEvents() = 0;
	virtual bool Update(const double& elapsedTime) = 0;
	virtual void Render() const = 0;
	virtual void End() = 0;

	Scenes GetNextState() const { return _nextScene; }

protected:
	virtual void DoStart() = 0;

	Scenes _nextScene;
	SDL_Renderer* _renderer;
};