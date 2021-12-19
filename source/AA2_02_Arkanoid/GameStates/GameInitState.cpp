#include "GameInitState.h"


GameInitState::GameInitState(SDL_Renderer* renderer, Controller* controller, FileManager* fileManager, 
	GameObjects* gameObjects, CollisionManager* collisionManager)
	: GameState(renderer, gameObjects), _controller(controller), _fileManager(fileManager), 
	_platformSpeed(), _collisionManager(collisionManager), _start(false), 
	_blackBackground(nullptr), _startGame(nullptr), _spaceToStart(nullptr)
{
}

GameInitState::~GameInitState()
{
}


void GameInitState::DoStart()
{
	std::cout << "GameInitState::Start\n";

	LoadGame();
	InitPlatforms();
	InitBall();
	InitBackground();
	InitTexts();
	_collisionManager->Init(_gameObjects->_platform1->GetCollider(), _gameObjects->_platform2->GetCollider());
}

void GameInitState::HandleEvents()
{
	if (_controller->GetButtonDown(ActionName::START)) {
		_start = true;
	}
}

bool GameInitState::Update(const double& elapsedTime)
{
	std::cout << "GameInitState::Update\n";
	
	if (_start) {
		_nextState = GameStates::RUNNING;
		return true;
	}

	_blackBackground->Update(elapsedTime);
	_startGame->Update(elapsedTime);
	_spaceToStart->Update(elapsedTime);

	return false;
}

void GameInitState::Render() const
{
	std::cout << "GameInitState::Render\n";

	SDL_RenderClear(_renderer);

	DrawGameObjects();
	_blackBackground->Render();
	_startGame->Render();
	_spaceToStart->Render();

	SDL_RenderPresent(_renderer);
}

void GameInitState::End()
{
	std::cout << "GameInitState::End\n";

	_start = false;

	delete _blackBackground;
	delete _startGame;
	delete _spaceToStart;
	_blackBackground = nullptr;
	_startGame = _spaceToStart = nullptr;
}



void GameInitState::LoadGame()
{
	GameData* gameData = _fileManager->LoadGameData("../../resources/files/configuration.xml");

	_platformSpeed = gameData->GetPlatformSpeed();
	_brickPoints = gameData->GetBrickPoints();

	BrickFactory brickFactory;
	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {
		_gameObjects->AddBrick(brickFactory.Create(_renderer, *it, ROTATED_BRICK_DESTINATION_SIZE, OFFSET, &_brickPoints));
	}

}

void GameInitState::InitPlatforms()
{
	_gameObjects->InitPlatforms(
		new Platform(_renderer, Vector2D<float>(PLATFORM_SOURCE_HEIGHT, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH), 
			PLATFORM_DESTINATION_SIZE, _platformSpeed),
		new Platform(_renderer, Vector2D<float>(SCREEN_WIDTH - 80, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH),
			PLATFORM_DESTINATION_SIZE, _platformSpeed)
	);
}

void GameInitState::InitBall()
{
	Vector2D<float> spawnPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Vector2D<float> spawnDirection(-1, 0);
	_gameObjects->InitBall( 
		new Ball(_renderer, spawnPosition, BALL_DESTINATION_SIZE, spawnDirection, _platformSpeed) 
	);
}

void GameInitState::InitBackground()
{
	_gameObjects->InitBackground( 
		new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg", 
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(0, 0), SCREEN_SIZE)
	);

	_blackBackground = new ImageGameObject(_renderer, "../../resources/assets/images/blackBackground.png",
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(0, 0), SCREEN_SIZE, 150);
}

void GameInitState::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_startGame = new TextGameObject(_renderer, "START GAME", white, Vector2D<int>(140, 200), 72);
	_spaceToStart = new TextGameObject(_renderer, "SPACE BAR TO START", white, Vector2D<int>(180, 280), 36);
}
