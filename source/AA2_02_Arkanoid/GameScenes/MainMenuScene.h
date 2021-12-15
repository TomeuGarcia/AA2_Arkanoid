#pragma once
#include "GameScene.h"

class MainMenuScene : public Scene {
public:
	MainMenuScene(SDL_Renderer* renderer, Player* player1);
	~MainMenuScene();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
};