#pragma once
#include <functional>
#include "GameState.h"
#include "../GameLogic/GameLogic.h"


class GameRunningState : public GameState {
public:
	GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2, 
		GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic, std::string* winnerTextStr, int* winnerScore);
	~GameRunningState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	void StartKickOff(Platform* kickOffPlatform);
	void UpdatePlayerScores();
	void BrickBreaks(const Vector2D<float> brickPosition, const int& brickPoints);

	void CheckBallExitingBoundaries();


	CollisionManager* _collisionManager;

	Controller* _controller1;
	Controller* _controller2;

	GameLogic* _gameLogic;

	std::string* _winnerTextStr;
	int* _winnerScore;
};