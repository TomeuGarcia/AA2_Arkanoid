#include "GameLogic.h"

GameLogic::GameLogic(const int& playerStartLives, const int& playerLivesLoss, const int& playerScoreLoss, const int& playerScoreGain)
	: _playerLivesLoss(playerLivesLoss), _playerScoreLoss(playerScoreLoss), _playerScoreGain(playerScoreGain),
	_player1(new Player(playerStartLives)), _player2(new Player(playerStartLives))
{
}

GameLogic::~GameLogic()
{
	delete _player1;
	delete _player2;
	_player1 = _player2 = nullptr;
}

void GameLogic::Player1LosesLives()
{
	_player1->LoseLives(_playerLivesLoss);
	_player1->LosePoints(_playerScoreLoss);
	_player2->GainPoints(_playerScoreGain);
}

void GameLogic::Player2LosesLives()
{
	_player2->LoseLives(_playerLivesLoss);
	_player2->LosePoints(_playerScoreLoss);
	_player1->GainPoints(_playerScoreGain);
}

void GameLogic::Player1DestroyedBrick(const int& brickScoreGain)
{
	_player1->GainPoints(brickScoreGain);
}

void GameLogic::Player2DestroyedBrick(const int& brickScoreGain)
{
	_player2->GainPoints(brickScoreGain);
}

std::string GameLogic::GetPlayer1ScoreStr()
{
	return std::to_string(_player1->GetScore());
}

std::string GameLogic::GetPlayer2ScoreStr()
{
	return std::to_string(_player2->GetScore());
}

bool GameLogic::Player1Lost()
{
	return _player1->Lost();
}

bool GameLogic::Player2Lost()
{
	return _player2->Lost();
}
