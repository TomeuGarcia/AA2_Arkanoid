#pragma once
#include "GameState.h"

class GameOverState : public GameState {
public:
	GameOverState();
	~GameOverState();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

};