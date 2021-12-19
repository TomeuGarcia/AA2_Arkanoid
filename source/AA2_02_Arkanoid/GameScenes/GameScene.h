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

#include "../Physics/CollissionManager.h"
#include "../GameLogic/GameLogic.h"

#include <map>
#include <list>

class GameScene : public Scene {
public:
	GameScene(SDL_Renderer* renderer);
	~GameScene();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	
	void InitControllers();

private:
	std::map< GameStates, GameState*> _gameStates;
	GameState* _currentGameState;
	bool _isStateFinished;

	GameLogic* _gameLogic;

	Controller* _controller1;
	Controller* _controller2;

	GameObjects* _gameObjects;

	FileManager* _fileManager;
	CollisionManager* _collissionManager;

	TextGameObject* _player1;
	TextGameObject* _player2;
};