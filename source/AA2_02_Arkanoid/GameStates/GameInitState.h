#pragma once
#include "GameState.h"
#include "../Brick/BrickFactory.h"
#include "../FileManaging/FileManager.h"
#include "../GameObjects/TextGameObject.h"
#include "../GameLogic/GameLogic.h"

class GameInitState : public GameState {
public:
	GameInitState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2, FileManager* fileManager,
		GameObjects* gameObjects, GameLogic* gameLogic);
	~GameInitState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	void InitBackground();
	void LoadGame();
	void InitPlatforms();
	void InitBall();
	void InitWalls();
	void InitTexts();
	void InitPlayerScoresAndLives();
	void InitPowerUpManager();


	FileManager* _fileManager;
	int _platformSpeed;
	int _ballSpeed;
	std::map<BrickType, std::pair<int, int>> _brickPoints;
	
	Controller* _controller1;
	Controller* _controller2;

	GameLogic* _gameLogic;

	ImageGameObject* _blackBackground;
	TextGameObject* _startGameText;
	TextGameObject* _spaceToStartText;
};