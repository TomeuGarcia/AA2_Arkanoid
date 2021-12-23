#pragma once
#include "GameState.h"

class GameOverState : public GameState {
public:
	GameOverState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects);
	~GameOverState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;
	void InitBlackBackground();
	void InitTexts();

private:
	Controller* _controller;
	ImageGameObject* _blackBackground;
	TextGameObject* _gameOverText;
	TextGameObject* _winnerText;
	TextGameObject* _goToRankingText;

};