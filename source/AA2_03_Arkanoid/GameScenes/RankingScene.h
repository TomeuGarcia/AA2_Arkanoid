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

private:
	void InitBackground();
	void InitTexts();
	void InitRanking();


	Controller* _controller;

	std::vector<TextGameObject*> _ranking;

	FileManager* _fileManager;
	std::list<RankingPlayer> _rankingPlayers;
};
