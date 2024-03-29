#pragma once
#include "SDL.h"
#include "../GameObjects/GameObjects.h"
#include "../Physics/CollissionManager.h"
#include "../Inputs/Keyboard.h"


enum class GameStates { NONE, INIT, RUNNING, PAUSED, GAME_OVER, QUIT_TO_RANKING, QUIT_TO_MAIN_MENU };


class GameState {

public:
	GameState(SDL_Renderer* renderer, GameObjects* gameObjects);
	virtual ~GameState() = default;

	void Start() {
		_nextState = GameStates::NONE;
		DoStart();
	}
	virtual bool Update(const double& elapsedTime) = 0;
	virtual void Render() const = 0;
	virtual void End() = 0;

	GameStates GetNextState() const { return _nextState; }
	void UpdateGameObjects(const double& elapsedTime);
	void RenderGameObjects() const;

protected:
	virtual void DoStart() = 0;

	GameStates _nextState;
	SDL_Renderer* _renderer;
	GameObjects* _gameObjects;
};