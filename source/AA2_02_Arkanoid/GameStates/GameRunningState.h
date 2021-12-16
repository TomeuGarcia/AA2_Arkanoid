#pragma once
#include "GameState.h"

class GameRunningState : public GameState {
public:
	GameRunningState(SDL_Renderer* renderer, GameObjects* gameObjects);
	~GameRunningState();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	
};