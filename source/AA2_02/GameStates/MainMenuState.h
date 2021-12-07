#pragma once
#include "GameState.h"

class MainMenuState : public GameState {
public:
	MainMenuState(Player* player1);
	~MainMenuState();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
};