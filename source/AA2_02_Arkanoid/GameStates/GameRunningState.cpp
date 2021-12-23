#include "GameRunningState.h"


GameRunningState::GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2,
	GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic)
	: GameState(renderer, gameObjects), _controller1(controller1), _controller2(controller2),
	_collisionManager(collisionManager), _gameLogic(gameLogic)
{
}

GameRunningState::~GameRunningState()
{
}

void GameRunningState::DoStart()
{	
	_gameObjects->_leftScoreWall->SetStartKickOffCallback(std::bind(&GameRunningState::Platform1StartKickOff, this));
	_gameObjects->_rightScoreWall->SetStartKickOffCallback(std::bind(&GameRunningState::Platform2StartKickOff, this));
}


bool GameRunningState::Update(const double& elapsedTime)
{
	if (_gameLogic->Player1Lost() || _gameLogic->Player2Lost()) {
		_nextState = GameStates::GAME_OVER;
		return true;
	}
	if (_controller1->GetButtonDown(ActionName::PAUSE)) {
		_nextState = GameStates::PAUSED;
		return true;
	}
	if (_controller1->GetButtonDown(ActionName::START) && _gameObjects->_platform1->IsGrabbing()) {
		_gameObjects->_platform1->SetIsGrabbing(false);
		_gameObjects->_ball->StartMoving();
	}
	if (_controller2->GetButtonDown(ActionName::START) && _gameObjects->_platform2->IsGrabbing()) {
		_gameObjects->_platform2->SetIsGrabbing(false);
		_gameObjects->_ball->StartMoving();
	}

	_gameObjects->_platform1->SetMoveDirection(Vector2D<float>(0, _controller1->GetAxis(AxisName::VERTICAL)));
	_gameObjects->_platform2->SetMoveDirection(Vector2D<float>(0, _controller2->GetAxis(AxisName::VERTICAL)));

	_collisionManager->Update();
	UpdateGameObjects(elapsedTime);
	UpdatePlayerScores();


	return false;
}

void GameRunningState::Render() const
{	
	SDL_RenderClear(_renderer);
	
	RenderGameObjects();

	SDL_RenderPresent(_renderer);
}

void GameRunningState::End()
{
}

void GameRunningState::UpdatePlayerScores()
{
	_gameObjects->UpdateScorePointsPlayer1(_gameLogic->GetPlayer1ScoreStr().c_str());
	_gameObjects->UpdateScorePointsPlayer2(_gameLogic->GetPlayer2ScoreStr().c_str());
}



void GameRunningState::Platform1StartKickOff()
{
	StartKickOff(_gameObjects->_platform1);
	_gameLogic->Player1GetsScored();
	_gameObjects->Player1LosesLives();
}

void GameRunningState::Platform2StartKickOff()
{
	StartKickOff(_gameObjects->_platform2);
	_gameLogic->Player2GetsScored();
	_gameObjects->Player2LosesLives();
}

void GameRunningState::StartKickOff(Platform* kickOffPlatform)
{
	kickOffPlatform->SetIsGrabbing(true);
	_gameObjects->_ball->StartFollowing(kickOffPlatform);
}


void GameRunningState::BrickIsDestroyed()
{
	/*_gameLogic->PlayerDestroyedBrick(_gameObjects->_ball->GetLastPlatform()->GetPlayer());

	_gameLogic->Player1DestroyedBrick()*/
}
