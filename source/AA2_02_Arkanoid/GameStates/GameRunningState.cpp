#include "GameRunningState.h"


GameRunningState::GameRunningState(SDL_Renderer* renderer, GameObjects* gameObjects)
	: GameState(renderer, gameObjects)
{
}

GameRunningState::~GameRunningState()
{
}

void GameRunningState::DoStart()
{
	std::cout << "GameRunningState::Start\n";
}

void GameRunningState::HandleEvents()
{
}

bool GameRunningState::Update(const double& elapsedTime)
{
	std::cout << "GameRunningState::Update\n";
	if (_gameObjects->_player1->GetController()->GetButtonDown(ActionName::PAUSE)) {
		_nextState = GameStates::PAUSED;
		return true;
	}
	// Simulating the game ended
	else if (_gameObjects->_player1->GetController()->GetButtonDown(ActionName::QUIT)) {
		_nextState = GameStates::GAME_OVER;
		return true;
	}


	_gameObjects->_player1->MovePlatform(Vector2D<float>(0, _gameObjects->_player1->GetController()->GetAxis(AxisName::VERTICAL)), elapsedTime);
	_gameObjects->_player2->MovePlatform(Vector2D<float>(0, _gameObjects->_player2->GetController()->GetAxis(AxisName::VERTICAL)), elapsedTime);

	_gameObjects->_ball->Move(Vector2D<float>(-1, 0), elapsedTime);



	// Test brick breaking
	if (_gameObjects->_player1->GetController()->GetButtonUp(ActionName::DOWN)) {
		for (std::list<Brick*>::const_iterator it = _gameObjects->_bricks.begin(); it != _gameObjects->_bricks.end(); ++it) {
			if ((*it)->DoCollision()) {
				std::list<Brick*>::const_iterator it2{ it };
				++it;
				_gameObjects->_bricks.erase(it2);
			}
		}
	}

	return false;
}

void GameRunningState::Render() const
{
	std::cout << "GameRunningState::Render\n";
	SDL_RenderClear(_renderer);
	DrawGameObjects();
	SDL_RenderPresent(_renderer);
}

void GameRunningState::End()
{
	std::cout << "GameRunningState::End\n";
}
