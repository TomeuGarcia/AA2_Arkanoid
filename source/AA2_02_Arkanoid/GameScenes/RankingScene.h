#pragma once
#include "GameScene.h"

class RankingScene : public Scene {
public:
	RankingScene(SDL_Renderer* renderer);
	~RankingScene();
	virtual void DoStart();
	virtual void HandleEvents();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Controller* _controller;
	bool _goToMainMenu;
};
