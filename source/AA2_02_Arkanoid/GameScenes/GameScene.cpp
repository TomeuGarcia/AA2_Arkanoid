#include "GameScene.h"

GameScene::GameScene(SDL_Renderer* renderer)
	: Scene(renderer), _gameLogic(nullptr),
	_fileManager(nullptr), _gameObjects(nullptr), _collissionManager(nullptr), _controller1(nullptr), _controller2(nullptr),
	_currentGameState(), _isStateFinished(false), _player1(nullptr), _player2(nullptr)
{
}

GameScene::~GameScene()
{
	delete _gameLogic;
	_gameLogic = nullptr;
	delete _controller1;
	delete _controller2;
	_controller1 = _controller2 = nullptr;
}

void GameScene::DoStart()
{
	std::cout << "GameGameScene::Start\n";

	InitControllers();
	_gameLogic = new GameLogic(3, 1, 50, 100);
	_collissionManager = new CollisionManager;
	_gameObjects = new GameObjects(_collissionManager);

	_fileManager = new FileManager;

	_isStateFinished = false;
	_gameStates[GameStates::INIT] = new GameInitState(_renderer, _controller1, _fileManager, _gameObjects);
	_gameStates[GameStates::RUNNING] = new GameRunningState(_renderer, _controller1, _controller2, _gameObjects, _collissionManager, _gameLogic);
	_gameStates[GameStates::PAUSED] = new GamePausedState(_renderer, _controller1, _gameObjects);
	_gameStates[GameStates::GAME_OVER] = new GameOverState(_renderer, _controller1, _gameObjects);
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

		if (_currentGameState->GetNextState() == GameStates::QUIT_TO_RANKING) {
			_nextScene = Scenes::RANKING;
			return true;
		}
		else if (_currentGameState->GetNextState() == GameStates::QUIT_TO_MAIN_MENU) {
			_nextScene = Scenes::MAIN_MENU;
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



void GameScene::InitControllers()
{
	_controller1 = new Keyboard("keyboardPlayer1");
	_controller1->AddActionKey(ActionName::UP, SDLK_w);
	_controller1->AddActionKey(ActionName::DOWN, SDLK_s);
	_controller1->AddAxisActionKeys(AxisName::VERTICAL, SDLK_s, SDLK_w);
	_controller1->AddActionKey(ActionName::PAUSE, SDLK_p);
	_controller1->AddActionKey(ActionName::RESUME, SDLK_l);
	_controller1->AddActionKey(ActionName::QUIT, SDLK_ESCAPE);
	_controller1->AddActionKey(ActionName::START, SDLK_SPACE);
	InputHandler::GetInstance()->AddController(_controller1);

	_controller2 = new Keyboard("keyboardPlayer2");
	_controller2->AddActionKey(ActionName::UP, SDLK_UP);
	_controller2->AddActionKey(ActionName::DOWN, SDLK_DOWN);
	_controller2->AddAxisActionKeys(AxisName::VERTICAL, SDLK_DOWN, SDLK_UP);
	InputHandler::GetInstance()->AddController(_controller2);
}
