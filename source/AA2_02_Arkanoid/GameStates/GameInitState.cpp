#include "GameInitState.h"


GameInitState::GameInitState(SDL_Renderer* renderer, Controller* controller, FileManager* fileManager, 
	GameObjects* gameObjects)
	: GameState(renderer, gameObjects), _controller(controller), _fileManager(fileManager), 
	_platformSpeed(), _start(false), _goToMainMenu(false),
	_startGameText(nullptr), _spaceToStartText(nullptr),
	_platform1VerticalMove(), _platform2VerticalMove()
{
}

GameInitState::~GameInitState()
{
}


void GameInitState::DoStart()
{
	std::cout << "GameInitState::Start\n";

	InitBackground();
	InitTexts(); 
	LoadGame();
	InitPlayerScoresAndLives();
	InitPlatforms();
	InitBall();
	InitWalls();
	
}

void GameInitState::HandleEvents()
{
	if (_controller->GetButtonDown(ActionName::START)) {
		_start = true;
	}
	if (_controller->GetButtonDown(ActionName::QUIT)) {
		_goToMainMenu = true;
	}

	_platform1VerticalMove = _controller->GetAxis(AxisName::VERTICAL); ///////////////////////////////////////////////
	_platform2VerticalMove = _controller->GetAxis(AxisName::VERTICAL); ///////////////////// REVISAAAAAAAAAR
}

bool GameInitState::Update(const double& elapsedTime)
{
	std::cout << "GameInitState::Update\n";
	
	if (_start) {
		_nextState = GameStates::RUNNING;
		return true;
	}
	else if (_goToMainMenu) {
		_nextState = GameStates::QUIT_TO_MAIN_MENU;
		return true;
	}

	_gameObjects->_platform1->SetMoveDirection(Vector2D<float>(0, _platform1VerticalMove));
	_gameObjects->_platform2->SetMoveDirection(Vector2D<float>(0, _platform2VerticalMove));

	_startGameText->Update(elapsedTime);
	_spaceToStartText->Update(elapsedTime);
	UpdateGameObjects(elapsedTime);

	return false;
}

void GameInitState::Render() const
{
	std::cout << "GameInitState::Render\n";

	SDL_RenderClear(_renderer);

	RenderGameObjects();
	_startGameText->Render();
	_spaceToStartText->Render();

	SDL_RenderPresent(_renderer);
}

void GameInitState::End()
{
	std::cout << "GameInitState::End\n";

	_start = _goToMainMenu = false;

	delete _startGameText;
	delete _spaceToStartText;
	_startGameText = _spaceToStartText = nullptr;
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

void GameInitState::InitPlayerScoresAndLives()
{
	SDL_Color color = { 200,0,0,255 };
	_gameObjects->InitPlayerScores(
		new TextGameObject(_renderer, "Pl1:", color, Vector2D<int>(100, 510), 36),
		new TextGameObject(_renderer, "0", color, Vector2D<int>(200, 510), 36),
		new TextGameObject(_renderer, "Pl2:", color, Vector2D<int>(480, 510), 36),
		new TextGameObject(_renderer, "0", color, Vector2D<int>(580, 510), 36));

	_gameObjects->InitPlayersLives(_renderer, "../../resources/assets/images/platform.png",
		PLATFORM_DESTINATION_SIZE, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE);
}
void GameInitState::InitPlatforms()
{
	_gameObjects->InitPlatforms(
		new Platform(_renderer, PLATFORM_1_START_POSITION, PLATFORM_DESTINATION_SIZE, _platformSpeed, 
			new Vector2D<float>(60, SCREEN_HEIGHT / 2 - PLATFORM_DESTINATION_WIDTH)),
		new Platform(_renderer, PLATFORM_2_START_POSITION, PLATFORM_DESTINATION_SIZE, _platformSpeed, 
			new Vector2D<float>(680, SCREEN_HEIGHT / 2 - PLATFORM_DESTINATION_WIDTH))
	);
}

void GameInitState::InitBall()
{
	Vector2D<float> spawnDirection(0, 0);
	_gameObjects->InitBall( 
		new Ball(_renderer, _gameObjects->_platform1->GetGrabPosition(), BALL_DESTINATION_SIZE, spawnDirection, _platformSpeed)
	);
}

void GameInitState::InitWalls()
{
	_gameObjects->InitWalls(
		new Wall(Vector2D<float>(10, 10), Vector2D<int>(780, 16)),		// top wall
		new Wall(Vector2D<float>(10, 470), Vector2D<int>(780, 16)),		// bottom wall
		new Wall(Vector2D<float>(10, 25), Vector2D<int>(16, 550)),		// left wall
		new Wall(Vector2D<float>(775, 25), Vector2D<int>(16, 550))		// right wall
	);
}

void GameInitState::InitBackground()
{
	_gameObjects->InitBackground( 
		new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg", 
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(0, 0), SCREEN_SIZE)
	);
}

void GameInitState::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_startGameText = new TextGameObject(_renderer, "START GAME", white, Vector2D<int>(140, 200), 72);
	_spaceToStartText = new TextGameObject(_renderer, "SPACE BAR TO START", white, Vector2D<int>(180, 280), 36);
}
