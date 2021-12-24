#pragma once
#include "Scene.h"

class MainMenuScene : public Scene {
public:
	MainMenuScene(SDL_Renderer* renderer, bool* isRunning);
	~MainMenuScene();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;
	void InitBackground();
	void InitTexts();
private:
	bool* _isRunning;

	Controller* _controller;
};