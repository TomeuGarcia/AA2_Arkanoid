#include "GameOverState.h"


GameOverState::GameOverState(SDL_Renderer* renderer, GameObjects* gameObjects) 
	: GameState(renderer, gameObjects)
{
}

GameOverState::~GameOverState()
{
}


void GameOverState::DoStart()
{
	std::cout << "GameOverState::Start\n";
}

void GameOverState::HandleEvents()
{
}

bool GameOverState::Update(const double& elapsedTime)
{
	std::cout << "GameOverState::Update\n";
	if (_gameObjects->_player1->GetController()->GetButtonDown(ActionName::RESUME)) {
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
