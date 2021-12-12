#pragma once
#include "Scene.h"
#include "../GameStates/GameState.h"
#include "../GameStates/GameRunningState.h"
#include "../GameStates/GamePausedState.h"
#include "../GameStates/GameOverState.h"
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