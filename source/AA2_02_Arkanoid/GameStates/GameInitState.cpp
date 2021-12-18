#include "GameInitState.h"


GameInitState::GameInitState(SDL_Renderer* renderer, FileManager* fileManager, GameObjects* gameObjects, CollisionManager* collisionManager)
	: GameState(renderer, gameObjects), _fileManager(fileManager), _platformSpeed(), _collisionManager(collisionManager)
{
}

GameInitState::~GameInitState()
{
}


void GameInitState::DoStart()
{
	std::cout << "GameInitState::Start\n";

	Keyboard* controllerPlayer1 = new Keyboard("keyboardPlayer1");
	controllerPlayer1->AddActionKey(ActionName::UP, SDLK_w);
	controllerPlayer1->AddActionKey(ActionName::DOWN, SDLK_s);
	controllerPlayer1->AddAxisActionKeys(AxisName::VERTICAL, SDLK_s, SDLK_w);
	controllerPlayer1->AddActionKey(ActionName::PAUSE, SDLK_p);
	controllerPlayer1->AddActionKey(ActionName::RESUME, SDLK_l);
	controllerPlayer1->AddActionKey(ActionName::QUIT, SDLK_ESCAPE);
	controllerPlayer1->AddActionKey(ActionName::START, SDLK_SPACE);
	InputHandler::GetInstance()->AddController(controllerPlayer1);

	Keyboard* controllerPlayer2 = new Keyboard("keyboardPlayer2");
	controllerPlayer2->AddActionKey(ActionName::UP, SDLK_UP);
	controllerPlayer2->AddActionKey(ActionName::DOWN, SDLK_DOWN);
	controllerPlayer2->AddAxisActionKeys(AxisName::VERTICAL, SDLK_DOWN, SDLK_UP);
	InputHandler::GetInstance()->AddController(controllerPlayer2);

	LoadGame();
	InitPlayers(controllerPlayer1, controllerPlayer2);
	InitBall();
	InitBackground();

	_collisionManager->Init(_gameObjects->_player1->GetPlatform()->GetCollider(), _gameObjects->_player2->GetPlatform()->GetCollider());
}

void GameInitState::HandleEvents()
{
}

bool GameInitState::Update(const double& elapsedTime)
{
	std::cout << "GameInitState::Update\n";
	
	_nextState = GameStates::RUNNING;
	return true;
}

void GameInitState::Render() const
{
	std::cout << "GameInitState::Render\n";

	SDL_RenderClear(_renderer);
	DrawGameObjects();
	SDL_RenderPresent(_renderer);
}

void GameInitState::End()
{
	std::cout << "GameInitState::End\n";
}



void GameInitState::LoadGame()
{
	GameData* gameData = _fileManager->LoadGameData("../../resources/files/configuration.xml");

	_platformSpeed = gameData->GetPlatformSpeed();
	_brickPoints = gameData->GetBrickPoints();

	BrickFactory brickFactory;
	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {
		_gameObjects->AddNewBrick(brickFactory.Create(_renderer, *it, ROTATED_BRICK_DESTINATION_SIZE, OFFSET, &_brickPoints));
	}

}

void GameInitState::InitPlayers(Controller* controllerPlayer1, Controller* controllerPlayer2)
{
	_gameObjects->_player1 = new Player(controllerPlayer1);
	_gameObjects->_player1->InitPlatform(_renderer, Vector2D<float>(PLATFORM_SOURCE_HEIGHT, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH), 
		PLATFORM_DESTINATION_SIZE, _platformSpeed);

	_gameObjects->_player2 = new Player(controllerPlayer2);
	_gameObjects->_player2->InitPlatform(_renderer, Vector2D<float>(SCREEN_WIDTH - 80, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH),
		PLATFORM_DESTINATION_SIZE, _platformSpeed);
}

void GameInitState::InitBall()
{
	Vector2D<float> spawnPosition(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	Vector2D<float> spawnDirection(-1, 0);
	_gameObjects->_ball = new Ball(_renderer, spawnPosition, BALL_DESTINATION_SIZE, spawnDirection, _platformSpeed);
}

void GameInitState::InitBackground()
{
	_gameObjects->_background = new Image(_renderer, Vector2D<int>(0, 0), SCREEN_SIZE,
											Vector2D<int>(0, 0), SCREEN_SIZE);
	_gameObjects->_background->Init("../../resources/assets/images/background.jpg");
}