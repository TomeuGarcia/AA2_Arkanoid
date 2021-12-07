#pragma once
#include "GameState.h"

class SplashScreenState : public GameState {
public:
	SplashScreenState(SDL_Renderer* renderer);
	~SplashScreenState();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	float _waitTime;
};