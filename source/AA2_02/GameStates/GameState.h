#pragma once
#include "../GameScenes/GameScene.h"

enum class GameStates { NONE, RUNNING, PAUSED, GAME_OVER, QUIT };


class GameState {

public:
	GameState(SDL_Renderer* renderer) : _nextState(GameStates::NONE), _renderer(renderer) {}
	virtual ~GameState() = default;

	void Start() {
		_nextState = GameStates::RUNNING;
		DoStart();
	}
	virtual bool Update(float elapsedTime) = 0;
	virtual void Render() const = 0;
	virtual void End() = 0;

	GameStates GetNextState() const { return _nextState; }

protected:
	virtual void DoStart() = 0;

	GameStates _nextState;
	SDL_Renderer* _renderer;
};