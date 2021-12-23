#pragma once
#include <string>
#include "../Player/Player.h"

class GameLogic
{
public:
	GameLogic(const int& playerStartLives, const int& playerLivesLoss, const int& playerScoreLoss, const int& playerScoreGain);
	~GameLogic();

	Player* GetPlayer1() const;
	Player* GetPlayer2() const;

	void PlayerGetsScored(Player* actingPlayer);
	void PlayerDestroyedBrick(Player* actingPlayer, const int& brickScoreGain);
	std::string GetPlayerScoreStr(Player* actingPlayer);

	bool Player1Lost() const;
	bool Player2Lost() const;


private:
	Player* _player1;
	Player* _player2;
	int _playerLivesLoss;
	int _playerScoreLoss;
	int _playerScoreGain;
};
