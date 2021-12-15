#pragma once
#include "GameState.h"

class GamePausedState : public GameState {
public:
	GamePausedState(SDL_Renderer* renderer, Player* player1);
	~GamePausedState();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

	void InitBlackbackground();

private:
	Player* _player1;
	Image* _blackBackground;
};
