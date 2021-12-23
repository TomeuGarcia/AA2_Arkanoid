#pragma once
#include <functional>
#include "GameState.h"
#include "../GameLogic/GameLogic.h"


class GameRunningState : public GameState {
public:
	GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2, 
		GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic);
	~GameRunningState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	void UpdatePlayerScores();

private:
	void Platform1StartKickOff();
	void Platform2StartKickOff();
	void StartKickOff(Platform* kickOffPlatform);

	void BrickIsDestroyed();


	CollisionManager* _collisionManager;

	Controller* _controller1;
	Controller* _controller2;

	GameLogic* _gameLogic;
};