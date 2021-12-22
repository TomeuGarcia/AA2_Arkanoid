#pragma once
#include "GameState.h"
#include "../GameLogic/GameLogic.h"

class GameRunningState : public GameState {
public:
	GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2, 
		GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic);
	~GameRunningState();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	void UpdatePlayerScores();

private:
	bool _goToPauseState;
	bool _quit;

	float _platform1VerticalMove;
	float _platform2VerticalMove;

	CollisionManager* _collisionManager;

	Controller* _controller1;
	Controller* _controller2;

	GameLogic* _gameLogic;
};