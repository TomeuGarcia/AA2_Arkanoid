#include "MainMenuState.h"


MainMenuState::MainMenuState(Player* player1) : GameState(), _player1(player1)
{
}

MainMenuState::~MainMenuState() 
{
}

void MainMenuState::DoStart()
{
	std::cout << "MainMenuState::Start\n";
}

bool MainMenuState::Update(float elapsedTime)
{
	std::cout << "MainMenuState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::START)) {
		_nextState = GameStates::GAME_RUNNING;
		return true;
	}
	else if (_player1->GetController()->GetButtonDown(ActionName::RANKING)) { 
		_nextState = GameStates::RANKING;
		return true;
	}
	else if (_player1->GetController()->GetButtonDown(ActionName::QUIT)) {
		_nextState = GameStates::GAME_OVER;
		return true;
	}

	return false;
}

void MainMenuState::Render() const
{
	std::cout << "MainMenuState::Render\n";
}

void MainMenuState::End()
{
	std::cout << "MainMenuState::End\n";
}
