#include "GameLogic.h"

GameLogic::GameLogic(const int& playerStartLives, const int& playerLivesLoss, const int& playerScoreLoss, const int& playerScoreGain)
	: _playerLivesLoss(playerLivesLoss), _playerScoreLoss(playerScoreLoss), _playerScoreGain(playerScoreGain),
	_player1(new Player("player1", playerStartLives)), _player2(new Player("player2", playerStartLives))
{
}

GameLogic::~GameLogic()
{
	delete _player1;
	delete _player2;
	_player1 = _player2 = nullptr;
}


Player* GameLogic::GetPlayer1() const
{
	return _player1;
}

Player* GameLogic::GetPlayer2() const
{
	return _player2;
}




void GameLogic::PlayerGetsScored(Player* actingPlayer)
{
	if (actingPlayer == _player1) {
		_player1->LoseLives(_playerLivesLoss);
		_player1->LosePoints(_playerScoreLoss);
		_player2->GainPoints(_playerScoreGain);
	}
	else if (actingPlayer == _player2) {
		_player2->LoseLives(_playerLivesLoss);
		_player2->LosePoints(_playerScoreLoss);
		_player1->GainPoints(_playerScoreGain);
	}
}

void GameLogic::PlayerDestroyedBrick(Player* actingPlayer, const int& brickScoreGain)
{
	actingPlayer->GainPoints(brickScoreGain);
}

std::string GameLogic::GetPlayerScoreStr(Player* actingPlayer)
{
	return std::to_string(actingPlayer->GetScore());
}

bool GameLogic::Player1Lost() const
{
	return _player1->Lost();
}

bool GameLogic::Player2Lost() const
{
	return _player2->Lost();
}
