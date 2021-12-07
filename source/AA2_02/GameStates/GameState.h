#pragma once
#include <iostream>
#include "../Inputs/InputHandler.h"
#include "../Player/Player.h"

enum class GameStates{NONE, SPLASH_SCREEN, MAIN_MENU, RANKING, GAME_RUNNING, GAME_PAUSED, GAME_OVER};

class GameState {

public:
	GameState(SDL_Renderer* renderer) : _nextState(GameStates::NONE), _renderer(renderer) {}
	virtual ~GameState() = default;

	void Start() {
		_nextState = GameStates::NONE;
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