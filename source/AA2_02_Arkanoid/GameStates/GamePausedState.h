#pragma once
#include "GameState.h"

class GamePausedState : public GameState {
public:
	GamePausedState(SDL_Renderer* renderer, GameObjects* gameObjects);
	~GamePausedState();
	virtual void DoStart() override;
	virtual void HandleEvents()  override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	void InitBlackBackground();

private:
	Image* _blackBackground;
	bool _goToRunningState;
};
