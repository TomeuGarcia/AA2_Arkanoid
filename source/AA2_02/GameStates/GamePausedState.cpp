#include "GamePausedState.h"


GamePausedState::GamePausedState(SDL_Renderer* renderer, Player* player1) : GameState(renderer), _player1(player1)
{
}

GamePausedState::~GamePausedState()
{
}

void GamePausedState::DoStart()
{
	std::cout << "GamePausedState::Start\n";
}

bool GamePausedState::Update(float elapsedTime)
{
	std::cout << "GamePausedState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::RESUME)) {
		_nextState = GameStates::GAME_RUNNING;
		return true;
	}

	return false;
}

void GamePausedState::Render() const
{
	std::cout << "GamePausedState::Render\n";
}

void GamePausedState::End()
{
	std::cout << "GamePausedState::End\n";
}
