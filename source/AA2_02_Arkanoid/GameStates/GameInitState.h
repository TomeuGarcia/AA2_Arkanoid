#pragma once
#include "GameState.h"
#include "../Brick/BrickFactory.h"
#include "../FileManaging/FileManager.h"
#include "../GameObjects/TextGameObject.h"

class GameInitState : public GameState {
public:
	GameInitState(SDL_Renderer* renderer, Controller* controller, FileManager* fileManager, GameObjects* gameObjects);
	~GameInitState();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	void InitBackground();
	void LoadGame();
	void InitPlatforms();
	void InitBall();
	void InitWalls();
	void InitTexts();
	void InitPlayerScoresAndLives();

private:
	bool _start;
	bool _goToMainMenu;
	FileManager* _fileManager;
	int _platformSpeed;
	std::map<BrickType, std::pair<int, int>> _brickPoints;
	
	Controller* _controller;

	ImageGameObject* _blackBackground;
	TextGameObject* _startGame;
	TextGameObject* _spaceToStart;
};