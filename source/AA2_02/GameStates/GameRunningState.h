#pragma once
#include "GameState.h"

class GameRunningState : public GameState {
public:
	GameRunningState(Player* player1);
	~GameRunningState();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
};