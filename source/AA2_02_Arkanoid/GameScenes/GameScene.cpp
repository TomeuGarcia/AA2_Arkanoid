#include "GameScene.h"

GameScene::GameScene(SDL_Renderer* renderer, Player* player1, Player* player2) 
	: Scene(renderer), _player1(player1), _player2(player2), _fileManager(), _ball(nullptr) {}

GameScene::~GameScene()
{
}

void GameScene::DoStart()
{
	std::cout << "GameGameScene::Start\n";

	_isStateFinished = false;

	LoadGame();
	InitPlayerPlatforms();
	InitBackground();
	InitBall();

	_gameStates[GameStates::RUNNING] = new GameRunningState(_renderer, _player1, _player2, _ball);
	_gameStates[GameStates::PAUSED] = new GamePausedState(_renderer, _player1);
	_gameStates[GameStates::GAME_OVER] = new GameOverState(_renderer, _player1);
	_currentGameState = _gameStates[GameStates::RUNNING];
	_currentGameState->Start();
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

	// Test brick breaking
	if (_player1->GetController()->GetButtonUp(ActionName::DOWN)) {
		for (std::list<Brick*>::const_iterator it = _bricks.begin(); it != _bricks.end(); ++it) {
			if ((*it)->DoCollision()) {
				std::list<Brick*>::const_iterator it2{ it };
				++it;
				_bricks.erase(it2);
			}
		}
	}

	return false;
}

void GameScene::Render() const
{
	std::cout << "GameGameScene::Render\n";

	SDL_RenderClear(_renderer);
	
	_background->Draw();
	_player1->GetPlatform()->Draw();
	_player2->GetPlatform()->Draw();

	for (std::list<Brick*>::const_iterator it = _bricks.begin(); it != _bricks.end(); ++it) {
		(*it)->Draw();
	}

	_ball->Draw();

	_currentGameState->Render();


	SDL_RenderPresent(_renderer);

}

void GameScene::End()
{
	std::cout << "GameGameScene::End\n";

	delete _ball;
}



void GameScene::LoadGame()
{
	GameData* gameData = _fileManager.LoadGameData("../../resources/files/configuration.xml");

	_platformSpeed = gameData->GetPlatformSpeed();
	_brickPoints = gameData->GetBrickPoints();


	Vector2D<int> start;
	Vector2D<int> offset((SCREEN_WIDTH / 2) - (BRICK_DESTINATION_HEIGHT * (ROWS / 2)), BRICK_SOURCE_WIDTH);

	BrickFactory brickFactory;

	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {	
		// Create Brick
		_bricks.push_back(brickFactory.Create(*it, &_brickPoints));

		// Init Brick sprite and its destination
		start = (*_bricks.rbegin())->GetPosition();
		start *= Vector2D<int>(BRICK_DESTINATION_HEIGHT, BRICK_DESTINATION_WIDTH);
		(*_bricks.rbegin())->InitSprite(_renderer, start + offset);
	}

}

void GameScene::InitBackground()
{
	_background = new Image(_renderer, Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 
									Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT));
	_background->Init("../../resources/assets/images/background.jpg");
}


void GameScene::InitPlayerPlatforms()
{
	_player1->GetPlatform()->Init(_renderer, Vector2D<int>(PLATFORM_SOURCE_HEIGHT, (SCREEN_HEIGHT/2) - PLATFORM_DESTINATION_WIDTH), 
								  PLATFORM_DESTINATION_SIZE, _platformSpeed);
	_player2->GetPlatform()->Init(_renderer, Vector2D<int>(SCREEN_WIDTH - 80, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH), 
								  PLATFORM_DESTINATION_SIZE, _platformSpeed);
}

void GameScene::InitBall()
{
	_ball = new Ball(Vector2D<int>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), _platformSpeed);
	_ball->InitSprite(_renderer);
}

