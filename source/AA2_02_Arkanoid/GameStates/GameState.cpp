#include "GameState.h"

GameState::GameState(SDL_Renderer* renderer, GameObjects* gameObjects) 
	: _nextState(GameStates::NONE), _renderer(renderer), _gameObjects(gameObjects) {}

void GameState::DrawGameObjects() const
{
	_gameObjects->_background->Draw();

	_gameObjects->_player1->GetPlatform()->Draw();
	_gameObjects->_player2->GetPlatform()->Draw();

	for (std::list<Brick*>::const_iterator it = _gameObjects->_bricks.begin(); it != _gameObjects->_bricks.end(); ++it) {
		(*it)->Draw();
	}

	_gameObjects->_ball->Draw();
}
