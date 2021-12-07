#pragma once
#include <iostream>
#include "../Inputs/InputHandler.h"
#include "../Player/Player.h"

enum class GameStates{NONE, SPLASH_SCREEN, MAIN_MENU, RANKING, GAME_RUNNING, GAME_PAUSED, GAME_OVER};

class GameState {

public:
	GameState() : _nextState(GameStates::NONE) {}
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

};