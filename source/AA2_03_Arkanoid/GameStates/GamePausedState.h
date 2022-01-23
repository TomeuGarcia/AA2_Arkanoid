#pragma once
#include "GameState.h"
#include "../GameObjects/ImageGameObject.h"
#include "../GameObjects/TextGameObject.h"
#include "../Audio/AudioHandler.h"

class GamePausedState : public GameState {
public:
	GamePausedState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects, Mix_Music* gameMusic);
	~GamePausedState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	void InitBlackBackground();
	void InitTexts();

	Controller* _controller;

	ImageGameObject* _blackBackground;
	TextGameObject* _pauseText;
	TextGameObject* _lToResumeText;

	Mix_Music* _gameMusic;
};
