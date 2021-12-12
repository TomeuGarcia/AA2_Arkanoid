#pragma once
#include "time.h"

#include "Scene.h"
#include "../GameStates/GameRunningState.h"
#include "../GameStates/GamePausedState.h"
#include "../GameStates/GameOverState.h"
#include "../Brick/FixBrick.h"
#include "../Brick/HeavyBrick.h"
#include "../Brick/NormalBrick.h"

#include "../FileManaging/FileManager.h"

#include <map>
#include <list>

class GameScene : public Scene {
public:
	GameScene(SDL_Renderer* renderer, Player* player1, Player* player2);
	~GameScene();
	virtual void DoStart();
	virtual bool Update(float elapsedTime);
	virtual void Render() const;
	virtual void End();

	void LoadGame();
	int GetRandomBrickPoints(const BrickType& brickType);

private:
	Player* _player1;
	Player* _player2;

	std::map< GameStates, GameState*> _gameStates;
	GameState* _currentGameState;
	bool _isStateFinished;

	int _platformSpeed;
	std::list<Brick*> _bricks;
	std::map<BrickType, std::pair<int, int>> _brickPoints;

	FileManager _fileManager;
};