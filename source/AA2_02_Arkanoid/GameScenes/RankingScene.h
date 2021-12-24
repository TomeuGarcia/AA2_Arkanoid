#pragma once
#include "GameScene.h"

class RankingScene : public Scene {
public:
	RankingScene(SDL_Renderer* renderer);
	~RankingScene();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;
	
	void InitBackground();
	void InitTexts();

private:
	Controller* _controller;

	std::vector<TextGameObject*> _ranking;
};
