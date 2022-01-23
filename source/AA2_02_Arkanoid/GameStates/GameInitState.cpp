#include "GameInitState.h"


GameInitState::GameInitState(SDL_Renderer* renderer, Controller* controller1, Controller* controller2, FileManager* fileManager,
	GameObjects* gameObjects, GameLogic* gameLogic)
	: GameState(renderer, gameObjects), _controller1(controller1), _controller2(controller2), _fileManager(fileManager),
	_platformSpeed(), _ballSpeed(), _startGameText(nullptr), _spaceToStartText(nullptr), _blackBackground(nullptr),
	_gameLogic(gameLogic)
{
}

GameInitState::~GameInitState()
{
}


void GameInitState::DoStart()
{
	InitBackground();
	InitTexts(); 
	LoadGame();
	InitPlayerScoresAndLives();
	InitPlatforms();
	InitBall();
	InitWalls();
	InitPlayers();
}

bool GameInitState::Update(const double& elapsedTime)
{	
	if (_controller1->GetButtonDown(ActionName::START)) {
		_nextState = GameStates::RUNNING;
		return true;
	}
	else if (_controller1->GetButtonDown(ActionName::QUIT)) {
		_nextState = GameStates::QUIT_TO_MAIN_MENU;
		return true;
	}

	_blackBackground->Update(elapsedTime);
	_startGameText->Update(elapsedTime);
	_spaceToStartText->Update(elapsedTime);
	UpdateGameObjects(elapsedTime);

	return false;
}

void GameInitState::Render() const
{
	RenderGameObjects();
	_blackBackground->Render();
	_startGameText->Render();
	_spaceToStartText->Render();
}

void GameInitState::End()
{
	delete _startGameText;
	delete _spaceToStartText;
	_startGameText = _spaceToStartText = nullptr;
	_gameLogic = nullptr;
}



void GameInitState::LoadGame()
{
	GameData* gameData = _fileManager->LoadGameData("../../resources/files/configuration.xml");

	_platformSpeed = gameData->GetPlatformSpeed();
	_ballSpeed = gameData->GetBallSpeed();
	_brickPoints = gameData->GetBrickPoints();

	BrickFactory brickFactory;
	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {
		_gameObjects->AddBrick(brickFactory.Create(_renderer, *it, ROTATED_BRICK_DESTINATION_SIZE, OFFSET, &_brickPoints));
	}

	PowerUpData powerUpData = gameData->GetPowerUpData();
	_gameObjects->InitPowerUpManager(_renderer, &powerUpData);
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
			new Vector2D<float>(60, SCREEN_HEIGHT / 2 - PLATFORM_DESTINATION_WIDTH), true, _gameLogic->GetPlayer1(),
			_controller1),
		new Platform(_renderer, PLATFORM_2_START_POSITION, PLATFORM_DESTINATION_SIZE, _platformSpeed, 
			new Vector2D<float>(710, SCREEN_HEIGHT / 2 - PLATFORM_DESTINATION_WIDTH), false, _gameLogic->GetPlayer2(),
			_controller2)
	);
}

void GameInitState::InitBall()
{
	_gameObjects->InitBall( 
		new Ball(_renderer, BALL_DESTINATION_SIZE, _ballSpeed, _gameObjects->_platform1)
	);
}

void GameInitState::InitWalls()
{
	_gameObjects->InitWalls(
		new Wall(Vector2D<float>(10, 10), Vector2D<int>(780, 16)),		// top wall
		new Wall(Vector2D<float>(10, 470), Vector2D<int>(780, 16)),		// bottom wall
		new ScoreWall(Vector2D<float>(10, 25), Vector2D<int>(16, 550), _gameObjects->_platform1),	// left score wall
		new ScoreWall(Vector2D<float>(775, 25), Vector2D<int>(16, 550), _gameObjects->_platform2)	// right score wall
	);

}

void GameInitState::InitBackground()
{
	_gameObjects->InitBackground( 
		new ImageGameObject(_renderer, "../../resources/assets/images/background.jpg", 
		Vector2D<int>(0, 0), SCREEN_SIZE, Vector2D<int>(0, 0), SCREEN_SIZE)
	);
	_blackBackground = new ImageGameObject(_renderer, "../../resources/assets/images/blackBackground.png",
		Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT), 150);
}

void GameInitState::InitTexts()
{
	SDL_Color white({ 255,255,255,255 });
	_startGameText = new TextGameObject(_renderer, "START GAME", white, Vector2D<int>(140, 200), 72);
	_spaceToStartText = new TextGameObject(_renderer, "SPACE BAR TO START", white, Vector2D<int>(180, 280), 36);


}

void GameInitState::InitPlayers()
{
	_gameLogic->SetPlayerPlatforms(_gameObjects->_platform1, _gameObjects->_platform2);

	_gameObjects->AddGameObjectToCollection(_gameLogic->GetPlayer1());
	_gameObjects->AddGameObjectToCollection(_gameLogic->GetPlayer2());
}
