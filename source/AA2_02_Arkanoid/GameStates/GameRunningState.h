#pragma once
#include "GameState.h"

class GameRunningState : public GameState {
public:
	GameRunningState(SDL_Renderer* renderer, Player* player1, Player* player2);
	~GameRunningState();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
	Player* _player2;
};