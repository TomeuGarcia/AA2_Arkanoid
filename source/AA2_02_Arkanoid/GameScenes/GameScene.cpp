#include "GameScene.h"

GameScene::GameScene(SDL_Renderer* renderer) 
	: Scene(renderer), _fileManager(nullptr), _gameObjects(nullptr), _collissionManager(nullptr), _currentGameState(), _isStateFinished(false) {}

GameScene::~GameScene()
{
}

void GameScene::DoStart()
{
	std::cout << "GameGameScene::Start\n";

	_isStateFinished = false;

	_fileManager = new FileManager;
	_gameObjects = new GameObjects;

	_gameStates[GameStates::INIT] = new GameInitState(_renderer, _fileManager, _gameObjects, _collissionManager);
	_gameStates[GameStates::RUNNING] = new GameRunningState(_renderer, _gameObjects, _collissionManager);
	_gameStates[GameStates::PAUSED] = new GamePausedState(_renderer, _gameObjects);
	_gameStates[GameStates::GAME_OVER] = new GameOverState(_renderer, _gameObjects);
	_currentGameState = _gameStates[GameStates::INIT];
	_currentGameState->Start();
}

void GameScene::HandleEvents()
{
	_currentGameState->HandleEvents();
}

bool GameScene::Update(const double& elapsedTime)
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

	_currentGameState->Render();
}

void GameScene::End()
{
	std::cout << "GameGameScene::End\n";

	delete _fileManager;
	delete _gameObjects;
	delete _collissionManager;
	InputHandler::GetInstance()->RemoveAllControllers();
}
