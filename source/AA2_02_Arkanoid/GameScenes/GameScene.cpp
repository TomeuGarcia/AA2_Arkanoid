#include "GameScene.h"

GameScene::GameScene(SDL_Renderer* renderer, Player* player1, Player* player2) 
	: Scene(renderer), _player1(player1), _player2(player2), _fileManager() {}

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

	LoadGame();
	InitBackgroundSprite();
	InitPlayerPlatforms();

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

	// Test brick breaking
	if (_player1->GetController()->GetButtonUp(ActionName::DOWN)) {
		for (std::list<Brick*>::const_iterator it = _bricks.begin(); it != _bricks.end(); ++it) {
			(*it)->NextSprite();
		}
	}

	int verticalDirection = _player1->GetController()->GetAxis(AxisName::VERTICAL);
	if (verticalDirection != 0) {
		_player1->MovePlatform(Vector2D<int>(0, verticalDirection), _platformSpeed * elapsedTime);
	}
	verticalDirection = _player2->GetController()->GetAxis(AxisName::VERTICAL);
	if (verticalDirection != 0) {
		_player2->MovePlatform(Vector2D<int>(0, verticalDirection), _platformSpeed * elapsedTime);
	}


	return false;
}

void GameScene::Render() const
{
	std::cout << "GameGameScene::Render\n";

	SDL_RenderClear(_renderer);
	
	_backgroundSprite->Draw();
	_player1->GetPlatform()->GetSprite()->Draw();
	_player2->GetPlatform()->GetSprite()->Draw();

	for (std::list<Brick*>::const_iterator it = _bricks.begin(); it != _bricks.end(); ++it) {
		(*it)->GetCurrentSprite()->Draw();
	}

	SDL_RenderPresent(_renderer);

}

void GameScene::End()
{
	std::cout << "GameGameScene::End\n";
}



void GameScene::LoadGame()
{
	GameData* gameData = _fileManager.LoadGameData("../../resources/XML/config.xml");

	_platformSpeed = gameData->GetPlatformSpeed();
	_brickPoints = gameData->GetBrickPoints();


	Vector2D<int> start;
	Vector2D<int> offset((SCREEN_WIDTH / 2) - (BRICK_SOURCE_HEIGHT * (COLUMNS / 2)), BRICK_SOURCE_WIDTH);

	BrickFactory brickFactory(_brickPoints);

	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {	
		// Create Brick
		_bricks.push_back(brickFactory.Create(*it));

		// Init Brick sprite and its destination
		start = (*_bricks.rbegin())->GetPosition();
		start *= Vector2D<int>(BRICK_SOURCE_HEIGHT, BRICK_SOURCE_WIDTH);
		(*_bricks.rbegin())->InitSprite(_renderer, start + offset);
	}

}

void GameScene::InitBackgroundSprite()
{
	_backgroundSprite = new Image(_renderer, Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 
									Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT));
	_backgroundSprite->Init("../../resources/Assets/Images/Background.jpg");
}


void GameScene::InitPlayerPlatforms()
{
	_player1->GetPlatform()->Init(_renderer, Vector2D<int>(PLATFORM_SOURCE_HEIGHT, (SCREEN_HEIGHT/2) - PLATFORM_DESTINATION_WIDTH), PLATFORM_SOURCE_SIZE);
	_player2->GetPlatform()->Init(_renderer, Vector2D<int>(SCREEN_WIDTH - 80, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH), PLATFORM_SOURCE_SIZE);
}

