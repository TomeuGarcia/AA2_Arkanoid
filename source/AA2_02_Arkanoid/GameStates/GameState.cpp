#include "GameState.h"

GameState::GameState(SDL_Renderer* renderer, GameObjects* gameObjects) 
	: _nextState(GameStates::NONE), _renderer(renderer), _gameObjects(gameObjects) {}


void GameState::DrawGameObjects() const
{
	for (std::vector<GameObject*>::reverse_iterator rit = _gameObjects->_gameObjectCollection.rbegin();
		rit != _gameObjects->_gameObjectCollection.rend(); ++rit) 
	{
		if (*rit != nullptr)
			(*rit)->Render();
	}



	//_gameObjects->_background->Render();

	//_gameObjects->_platform1->Render();
	//_gameObjects->_platform2->Render();

	//for (std::list<Brick*>::const_iterator it = _gameObjects->_bricks.begin(); it != _gameObjects->_bricks.end(); ++it) {
	//	if (*it)
	//		(*it)->Render();
	//}

	//_gameObjects->_ball->Render();
}
