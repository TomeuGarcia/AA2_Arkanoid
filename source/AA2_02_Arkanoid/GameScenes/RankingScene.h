#pragma once
#include "GameScene.h"

class RankingScene : public Scene {
public:
	RankingScene(SDL_Renderer* renderer);
	~RankingScene();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;
	
	void InitBackground();
	void InitTexts();

private:
	Controller* _controller;
	bool _goToMainMenu;
	ImageGameObject* _background;

	TextGameObject* _title;
	std::vector<TextGameObject*> _ranking;
	TextGameObject* _mainMenuText;
};
