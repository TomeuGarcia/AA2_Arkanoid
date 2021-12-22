#include "GameState.h"

GameState::GameState(SDL_Renderer* renderer, GameObjects* gameObjects) 
	: _nextState(GameStates::NONE), _renderer(renderer), _gameObjects(gameObjects) {}


void GameState::UpdateGameObjects(const double& elapsedTime)
{
	_gameObjects->Update(elapsedTime);
}

void GameState::RenderGameObjects() const
{
	_gameObjects->Render();
}
