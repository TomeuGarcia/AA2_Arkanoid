#include "GameOverState.h"


GameOverState::GameOverState(SDL_Renderer* renderer, Player* player1) : GameState(renderer), _player1(player1)
{
}

GameOverState::~GameOverState()
{
}


void GameOverState::DoStart()
{
	std::cout << "GameOverState::Start\n";
}

bool GameOverState::Update(const double& elapsedTime)
{
	std::cout << "GameOverState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::START)) {
		_nextState = GameStates::QUIT;
		return true;
	}
	return false;
}

void GameOverState::Render() const
{
	std::cout << "GameOverState::Render\n";
}

void GameOverState::End()
{
	std::cout << "GameOverState::End\n";
}
