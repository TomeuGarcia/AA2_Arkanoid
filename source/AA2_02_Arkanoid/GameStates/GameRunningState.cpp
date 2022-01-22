#include "GameRunningState.h"


GameRunningState::GameRunningState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2,
	GameObjects* gameObjects, CollisionManager* collisionManager, GameLogic* gameLogic, std::string* winnerTextStr, int* winnerScore)
	: GameState(renderer, gameObjects), _controller1(controller1), _controller2(controller2),
	_collisionManager(collisionManager), _gameLogic(gameLogic), _winnerTextStr(winnerTextStr), _winnerScore(winnerScore)
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
		(*it)->SetBrickBreaksCallback(std::bind(&GameRunningState::BrickBreaks, this, std::placeholders::_1, std::placeholders::_2));
	}
}


bool GameRunningState::Update(const double& elapsedTime)
{
	if (_gameLogic->DidPlayer1Lose()) {
		*_winnerTextStr = "Player 2";
		*_winnerScore = _gameObjects->_platform2->GetPlayer()->GetScore();
		_nextState = GameStates::GAME_OVER;
		return true;
	}
	else if (_gameLogic->DidPlayer2Lose()) {
		*_winnerTextStr = "Player 1";
		*_winnerScore = _gameObjects->_platform1->GetPlayer()->GetScore();
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

	CheckBallExitingBoundaries();

	return false;
}

void GameRunningState::Render() const
{		
	RenderGameObjects();
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


void GameRunningState::BrickBreaks(const Vector2D<float> brickPosition, const int& brickPoints)
{
	_gameLogic->PlayerDestroyedBrick(_gameObjects->_ball->GetLastPlatform()->GetPlayer(), brickPoints);
	UpdatePlayerScores();


	Vector2D<float> powerUpMoveDirection(0, 0);
	powerUpMoveDirection.X = _gameObjects->_ball->GetLastPlatform()->GetCentrePosition().X > _gameObjects->_ball->GetCentrePosition().X ? 1 : -1;
	_gameObjects->_powerUpManager->TrySpawnPowerUp(brickPosition, powerUpMoveDirection);
}

void GameRunningState::CheckBallExitingBoundaries()
{
	SDL_Rect gameRect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	Vector2D<int> ballPosition(_gameObjects->_ball->GetCentrePosition().X, _gameObjects->_ball->GetCentrePosition().Y);

	if (!CollisionsHelper::IsPointInsideRect(&gameRect, &ballPosition)) {
		StartKickOff(_gameObjects->_ball->GetLastPlatform());
	}
}
