#pragma once
#include "GameState.h"

class GameOverState : public GameState {
public:
	GameOverState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects, std::string* winnerTextStr);
	~GameOverState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	void InitBlackBackground();
	void InitTexts();

	Controller* _controller;
	ImageGameObject* _blackBackground;
	TextGameObject* _gameOverText;
	TextGameObject* _winnerText;
	TextGameObject* _goToRankingText;

	std::string* _winnerTextStr;
};