#pragma once
#include "GameState.h"

class GameOverState : public GameState {
public:
	GameOverState(SDL_Renderer* renderer, GameObjects* gameObjects);
	~GameOverState();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:

};