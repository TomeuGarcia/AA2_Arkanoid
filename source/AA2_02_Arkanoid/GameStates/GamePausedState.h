#pragma once
#include "GameState.h"
#include "../GameObjects/ImageGameObject.h"
#include "../GameObjects/TextGameObject.h"

class GamePausedState : public GameState {
public:
	GamePausedState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects);
	~GamePausedState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

	void InitBlackBackground();
	void InitTexts();

private:
	Controller* _controller;

	ImageGameObject* _blackBackground;
	TextGameObject* _pauseText;
	TextGameObject* _lToResumeText;
};
