#include "GameScene.h"


GameScene::GameScene(SDL_Renderer* renderer, Player* player1, Player* player2) : Scene(renderer), _player1(player1), _player2(player2)
{
}

GameScene::~GameScene()
{
}

void GameScene::DoStart()
{
	std::cout << "GameGameScene::Start\n";

	_isStateFinished = false;

	_gameStates[GameStates::RUNNING] = new GameRunningState(_renderer, _player1, _player2);
	_gameStates[GameStates::PAUSED] = new GamePausedState(_renderer, _player1);
	_gameStates[GameStates::GAME_OVER] = new GameOverState(_renderer, _player1);

	_currentGameState = _gameStates[GameStates::RUNNING];
	_currentGameState->Start();
}

bool GameScene::Update(float elapsedTime)
{
	std::cout << "GameGameScene::Update\n";

	_isStateFinished = _currentGameState->Update(elapsedTime);
	if (_isStateFinished) {

		_currentGameState->End();

		if (_currentGameState->GetNextState() == GameStates::QUIT) {
			_nextScene = Scenes::RANKING;
			return true;
		}
		else {
			_currentGameState = _gameStates[_currentGameState->GetNextState()];
			_currentGameState->Start();
		}

	}

	return false;
}

void GameScene::Render() const
{
	std::cout << "GameGameScene::Render\n";

}

void GameScene::End()
{
	std::cout << "GameGameScene::End\n";
}
