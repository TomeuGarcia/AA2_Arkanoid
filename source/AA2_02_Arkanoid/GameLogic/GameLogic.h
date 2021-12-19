#pragma once
#include "../Player/Player.h"

class GameLogic
{
public:
	GameLogic(const int &lives,const int &liveslost, const int &scoreLost, const int &scoreGain);
private:
	Player* _player1;
	Player* _player2;
	int _playerStartLives;
	int _playerLivesLoss;
	int _playerScoreLoss;
	int _playerScoreGain;
};
