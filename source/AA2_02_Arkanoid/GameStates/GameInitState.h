#pragma once
#include "GameState.h"
#include "../Brick/BrickFactory.h"
#include "../FileManaging/FileManager.h"

class GameInitState : public GameState {
public:
	GameInitState(SDL_Renderer* renderer, FileManager* fileManager, GameObjects* gameObjects);
	~GameInitState();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	void LoadGame();
	void InitPlayers(Controller* controllerPlayer1, Controller* controllerPlayer2);
	void InitBall();
	void InitBackground();

private:
	FileManager* _fileManager;
	int _platformSpeed;
	std::map<BrickType, std::pair<int, int>> _brickPoints;
	
};