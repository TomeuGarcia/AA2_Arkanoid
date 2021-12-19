#pragma once
#include "Scene.h"

class MainMenuScene : public Scene {
public:
	MainMenuScene(SDL_Renderer* renderer);
	~MainMenuScene();
	virtual void DoStart() override;
	virtual void HandleEvents() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;
	void InitBackground();
	void InitText();
private:
	Controller* _controller;

	bool _goToGameScene;
	bool _goToRankingScene;
	bool _quitGame;

	ImageGameObject* _background;
	TextGameObject* _title;
	
};