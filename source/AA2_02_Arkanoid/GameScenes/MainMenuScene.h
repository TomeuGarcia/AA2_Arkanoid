#pragma once
#include "GameScene.h"

class MainMenuScene : public Scene {
public:
	MainMenuScene(SDL_Renderer* renderer);
	~MainMenuScene();
	virtual void DoStart();
	virtual void HandleEvents();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Controller* _controller;

	bool _goToGameScene;
	bool _goToRankingScene;
	bool _quitGame;
};