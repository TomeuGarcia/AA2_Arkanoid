#include "GameRunningState.h"


GameRunningState::GameRunningState(Player* player1) : GameState(), _player1(player1)
{
}

GameRunningState::~GameRunningState()
{
}

void GameRunningState::DoStart()
{
	std::cout << "GameRunningState::Start\n";
}

bool GameRunningState::Update(float elapsedTime)
{
	std::cout << "GameRunningState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::PAUSE)) {
		_nextState = GameStates::GAME_PAUSED;
		return true;
	}
	else if (_player1->GetController()->GetButtonDown(ActionName::QUIT)) {
		_nextState = GameStates::GAME_OVER;
		return true;
	}

	return false;
}

void GameRunningState::Render() const
{
	std::cout << "GameRunningState::Render\n";
}

void GameRunningState::End()
{
	std::cout << "GameRunningState::End\n";
}
