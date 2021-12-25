#include "GameRunningState.h"


GameRunningState::GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2,
	GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic, std::string* winnerTextStr)
	: GameState(renderer, gameObjects), _controller1(controller1), _controller2(controller2),
	_collisionManager(collisionManager), _gameLogic(gameLogic), _winnerTextStr(winnerTextStr)
{
}

GameRunningState::~GameRunningState()
{
}

void GameRunningState::DoStart()
{	
	// Set ScoreWalls callback
	_gameObjects->_leftScoreWall->SetStartKickOffCallback(std::bind(&GameRunningState::StartKickOff, this, std::placeholders::_1));
	_gameObjects->_rightScoreWall->SetStartKickOffCallback(std::bind(&GameRunningState::StartKickOff, this, std::placeholders::_1));

	// Set Bricks callback
	for (std::vector<Brick*>::iterator it = _gameObjects->_bricks.begin(); it != _gameObjects->_bricks.end(); ++it) {
		(*it)->SetBrickBreaksCallback(std::bind(&GameRunningState::BrickBreaks, this, std::placeholders::_1));
	}
}


bool GameRunningState::Update(const double& elapsedTime)
{
	if (_gameLogic->Player1Lost()) {
		*_winnerTextStr = "Player 2";
		_nextState = GameStates::GAME_OVER;
		return true;
	}
	else if (_gameLogic->Player2Lost()) {
		*_winnerTextStr = "Player 1";
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

	_collisionManager->Update();
	UpdateGameObjects(elapsedTime);

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
	_gameObjects->UpdateScorePointsPlayer1(_gameLogic->GetPlayerScoreStr(_gameLogic->GetPlayer1()).c_str());
	_gameObjects->UpdateScorePointsPlayer2(_gameLogic->GetPlayerScoreStr(_gameLogic->GetPlayer2()).c_str());
}



void GameRunningState::StartKickOff(Platform* kickOffPlatform)
{
	_gameLogic->PlayerGetsScored(kickOffPlatform->GetPlayer());
	_gameObjects->PlayerLosesLives(kickOffPlatform->GetPlayer());
	UpdatePlayerScores();

	kickOffPlatform->SetIsGrabbing(true);
	_gameObjects->_ball->StartFollowing(kickOffPlatform);
}


void GameRunningState::BrickBreaks(const int& brickPoints)
{
	_gameLogic->PlayerDestroyedBrick(_gameObjects->_ball->GetLastPlatform()->GetPlayer(), brickPoints);
	UpdatePlayerScores();
}
