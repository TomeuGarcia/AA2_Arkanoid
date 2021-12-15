#pragma once
#include "GameScene.h"

class RankingScene : public Scene {
public:
	RankingScene(SDL_Renderer* renderer, Player* player1);
	~RankingScene();
	virtual void DoStart();
	virtual bool Update(const double& elapsedTime);
	virtual void Render() const;
	virtual void End();

private:
	Player* _player1;
};
