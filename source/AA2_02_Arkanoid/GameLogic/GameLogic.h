#pragma once
#include <string>
#include "../Player/Player.h"

class GameLogic
{
public:
	GameLogic(const int& playerStartLives, const int& playerLivesLoss, const int& playerScoreLoss, const int& playerScoreGain);
	~GameLogic();

	void Player1LosesLives();
	void Player2LosesLives();
	void Player1DestroyedBrick(const int& brickScoreGain);
	void Player2DestroyedBrick(const int& brickScoreGain);
	std::string GetPlayer1ScoreStr();
	std::string GetPlayer2ScoreStr();
	bool Player1Lost();
	bool Player2Lost();

private:
	Player* _player1;
	Player* _player2;
	int _playerLivesLoss;
	int _playerScoreLoss;
	int _playerScoreGain;
};
