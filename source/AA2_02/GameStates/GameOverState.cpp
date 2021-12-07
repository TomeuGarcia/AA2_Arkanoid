#include "GameOverState.h"


GameOverState::GameOverState() : GameState()
{
}

GameOverState::~GameOverState()
{
}


void GameOverState::DoStart()
{
	std::cout << "GameOverState::Start\n";
}

bool GameOverState::Update(float elapsedTime)
{
	std::cout << "GameOverState::Update\n";
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
