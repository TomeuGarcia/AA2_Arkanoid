#pragma once
#include "GameState.h"

class GameOverState : public GameState {
public:
	GameOverState(SDL_Renderer* renderer, Player* player1);
	~GameOverState();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
};