#pragma once
#include "Scene.h"
#include "GameState.h"
#include "GameRunningState.h"
#include "GamePausedState.h"
#include "GameOverState.h"
#include <map>


class GameScene : public Scene {
public:
	GameScene(SDL_Renderer* renderer, Player* player1, Player* player2);
	~GameScene();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
	Player* _player2;

	std::map< GameStates, GameState*> _gameStates;
	GameState* _currentGameState;

	bool _isStateFinished;
};