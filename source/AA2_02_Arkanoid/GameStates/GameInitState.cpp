#include "GameInitState.h"


GameInitState::GameInitState(SDL_Renderer* renderer, FileManager* fileManager, GameObjects* gameObjects) 
	: GameState(renderer, gameObjects), _fileManager(fileManager), _platformSpeed()
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


	Vector2D<int> start;
	Vector2D<int> offset((SCREEN_WIDTH / 2) - (BRICK_DESTINATION_HEIGHT * (ROWS / 2)), BRICK_SOURCE_WIDTH);

	BrickFactory brickFactory;

	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {
		// Create Brick
		/*_gameObjects->_bricks.push_back(brickFactory.Create(*it, &_brickPoints));

		Brick* newBrick = brickFactory.Create(*it, &_brickPoints);
		_gameObjects->_bricks.push_back(newBrick);*/

		_gameObjects->AddNewBrick(brickFactory.Create(*it, &_brickPoints));

		// Init Brick sprite and its destination
		start = (*(_gameObjects->_bricks.rbegin()))->GetPosition();
		start *= Vector2D<int>(BRICK_DESTINATION_HEIGHT, BRICK_DESTINATION_WIDTH);
		(*(_gameObjects->_bricks.rbegin()))->InitSprite(_renderer, start + offset);
	}

}

void GameInitState::InitPlayers(Controller* controllerPlayer1, Controller* controllerPlayer2)
{
	_gameObjects->_player1 = new Player(controllerPlayer1);
	_gameObjects->_player1->GetPlatform()->Init(_renderer, Vector2D<float>(PLATFORM_SOURCE_HEIGHT, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH),
		PLATFORM_DESTINATION_SIZE, _platformSpeed);

	_gameObjects->_player2 = new Player(controllerPlayer2);
	_gameObjects->_player2->GetPlatform()->Init(_renderer, Vector2D<float>(SCREEN_WIDTH - 80, (SCREEN_HEIGHT / 2) - PLATFORM_DESTINATION_WIDTH),
		PLATFORM_DESTINATION_SIZE, _platformSpeed);
}

void GameInitState::InitBall()
{
	_gameObjects->_ball = new Ball(Vector2D<float>(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2), _platformSpeed);
	_gameObjects->_ball->InitSprite(_renderer);
}

void GameInitState::InitBackground()
{
	_gameObjects->_background = new Image(_renderer, Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT),
											Vector2D<int>(0, 0), Vector2D<int>(SCREEN_WIDTH, SCREEN_HEIGHT));
	_gameObjects->_background->Init("../../resources/assets/images/background.jpg");
}