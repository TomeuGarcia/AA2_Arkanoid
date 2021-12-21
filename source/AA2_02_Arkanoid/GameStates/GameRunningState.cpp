#include "GameRunningState.h"


GameRunningState::GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2,
	GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic)
	: GameState(renderer, gameObjects), _controller1(controller1), _controller2(controller2),
	_goToPauseState(false), _quit(false), _collisionManager(collisionManager), _gameLogic(gameLogic)
{
}

GameRunningState::~GameRunningState()
{
}

void GameRunningState::DoStart()
{
	std::cout << "GameRunningState::Start\n";
	_goToPauseState = false;
	_quit = false;
}

void GameRunningState::HandleEvents()
{
	if (_controller1->GetButtonDown(ActionName::PAUSE)) {
		_goToPauseState = true;
	}

	_platform1VerticalMove = _controller1->GetAxis(AxisName::VERTICAL);
	_platform2VerticalMove = _controller2->GetAxis(AxisName::VERTICAL);
}

bool GameRunningState::Update(const double& elapsedTime)
{
	std::cout << "GameRunningState::Update\n";
	if (_goToPauseState) {
		_nextState = GameStates::PAUSED;
		return true;
	}


	_gameObjects->_platform1->SetMoveDirection(Vector2D<float>(0, _platform1VerticalMove));
	_gameObjects->_platform2->SetMoveDirection(Vector2D<float>(0, _platform2VerticalMove));

	_collisionManager->Update();
	_gameObjects->Update(elapsedTime);



	// Simulating the game ended
	if (_gameLogic->Player1Lost() || _gameLogic->Player2Lost()) {
		_nextState = GameStates::GAME_OVER;
		return true;
	}

	// Test brick breaking
	if (_controller1->GetButtonUp(ActionName::DOWN)) {
		for (std::list<Brick*>::iterator it = _gameObjects->_bricks.begin(); it != _gameObjects->_bricks.end(); ++it) {
			if ((*it)->IsActive()) {
				(*it)->SetActive(!(*it)->DoCollision());
			}
		}
	}

	// Test lives and score
	if (_controller1->GetButtonUp(ActionName::UP)) {
		_gameLogic->Player1LosesLives();
		//_gameObjects->Player1LosesLives();
		_gameObjects->UpdateScorePointsPlayer1(_gameLogic->GetPlayer1ScoreStr().c_str());
		_gameObjects->UpdateScorePointsPlayer2(_gameLogic->GetPlayer2ScoreStr().c_str());
	}
	if (_controller2->GetButtonUp(ActionName::UP)) {
		_gameLogic->Player2LosesLives();
		//_gameObjects->Player2LosesLives();
		_gameObjects->UpdateScorePointsPlayer1(_gameLogic->GetPlayer1ScoreStr().c_str());
		_gameObjects->UpdateScorePointsPlayer2(_gameLogic->GetPlayer2ScoreStr().c_str());
	}


	return false;
}

void GameRunningState::Render() const
{
	std::cout << "GameRunningState::Render\n";
	
	SDL_RenderClear(_renderer);
	
	RenderGameObjects();

	SDL_RenderPresent(_renderer);
}

void GameRunningState::End()
{
	std::cout << "GameRunningState::End\n";
	_goToPauseState = false;
	_quit = false;
}
