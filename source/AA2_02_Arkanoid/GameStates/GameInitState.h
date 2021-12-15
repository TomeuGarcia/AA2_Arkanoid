#pragma once
#include "GameState.h"
#include "../Brick/BrickFactory.h"
#include "../FileManaging/FileManager.h"
#include "../GameObjects/GameObjects.h"

class GameInitState : public GameState {
public:
	GameInitState(SDL_Renderer* renderer, FileManager* fileManager, GameObjects* gameObjects);
	~GameInitState();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

	void LoadGame();
	void InitPlayers(Controller* controllerPlayer1, Controller* controllerPlayer2);
	void InitBall();
	void InitBackground();

private:
	FileManager* _fileManager;
	int _platformSpeed;
	std::map<BrickType, std::pair<int, int>> _brickPoints;
	GameObjects* _gameObjects;
};