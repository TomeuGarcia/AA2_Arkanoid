#pragma once
#include "GameState.h"
#include "../FileManaging/FileManager.h"
#include <set>


class GameOverState : public GameState {
public:
	GameOverState(SDL_Renderer* renderer, Controller* controller, GameObjects* gameObjects, 
		RankingPlayer* rankingPlayer, FileManager* fileManager);
	~GameOverState();
	virtual void DoStart() override;
	virtual bool Update(const double& elapsedTime) override;
	virtual void Render() const override;
	virtual void End() override;

private:
	void InitBlackBackground();
	void InitTexts();
	
	void AskWinnerName();
	void LoadRanking();
	bool UpdateRanking();
	void StoreRanking();


	Controller* _controller;
	ImageGameObject* _blackBackground;
	TextGameObject* _gameOverText;
	TextGameObject* _winnerText;
	TextGameObject* _goToRankingText;

	RankingPlayer* _winnerRankingPlayer;

	FileManager* _fileManager;
	std::list<RankingPlayer> _rankingPlayers;

	bool _sceneWasShown;
};