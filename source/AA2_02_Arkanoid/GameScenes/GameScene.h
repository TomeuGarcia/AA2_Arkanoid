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
	GameScene(SDL_Renderer* renderer);
	~GameScene();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	std::map< GameStates, GameState*> _gameStates;
	GameState* _currentGameState;
	bool _isStateFinished;

	FileManager* _fileManager;
	GameObjects* _gameObjects;
};