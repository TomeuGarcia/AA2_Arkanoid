#include "GameRunningState.h"


GameRunningState::GameRunningState(SDL_Renderer* renderer, Player* player1, Player* player2, Ball* ball) 
	: GameState(renderer), _player1(player1), _player2(player2), _ball(ball)
{
}

GameRunningState::~GameRunningState()
{
}

void GameRunningState::DoStart()
{
	std::cout << "GameRunningState::Start\n";
}

bool GameRunningState::Update(const double& elapsedTime)
{
	std::cout << "GameRunningState::Update\n";
	if (_player1->GetController()->GetButtonDown(ActionName::PAUSE)) {
		_nextState = GameStates::PAUSED;
		return true;
	}
	// Simulating the game ended
	else if (_player1->GetController()->GetButtonDown(ActionName::QUIT)) {
		_nextState = GameStates::GAME_OVER;
		return true;
	}


	_player1->MovePlatform(Vector2D<int>(0, _player1->GetController()->GetAxis(AxisName::VERTICAL)), elapsedTime);
	_player2->MovePlatform(Vector2D<int>(0, _player2->GetController()->GetAxis(AxisName::VERTICAL)), elapsedTime);

	_ball->Move(Vector2D<int>(-1, 0), elapsedTime);


	return false;
}

void GameRunningState::Render() const
{
	std::cout << "GameRunningState::Render\n";
	//SDL_RenderClear(_renderer);
	//SDL_RenderPresent(_renderer);
}

void GameRunningState::End()
{
	std::cout << "GameRunningState::End\n";
}
