#pragma once
#include "time.h"

#include "Scene.h"
#include "../GameStates/GameInitState.h"
#include "../GameStates/GameRunningState.h"
#include "../GameStates/GamePausedState.h"
#include "../GameStates/GameOverState.h"

#include "../Brick/BrickFactory.h"
#include "../Ball/Ball.h"

#include "../FileManaging/FileManager.h"
#include "../GameObjects/GameObjects.h"

#include <map>
#include <list>

class GameScene : public Scene {
public:
	GameScene(SDL_Renderer* renderer, Player* player1, Player* player2);
	~GameScene();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

	void LoadGame();
	void InitBackground();
	void InitPlayerPlatforms();
	void InitBall();

private:
	std::map< GameStates, GameState*> _gameStates;
	GameState* _currentGameState;
	bool _isStateFinished;



	FileManager _fileManager;

	GameObjects* _gameObjects;
};