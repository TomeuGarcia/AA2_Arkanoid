#pragma once
#include "GameState.h"
#include "../Ball/Ball.h"

class GameRunningState : public GameState {
public:
	GameRunningState(SDL_Renderer* renderer, Player* player1, Player* player2, Ball* ball);
	~GameRunningState();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
	Player* _player2;

	Ball* _ball;
};