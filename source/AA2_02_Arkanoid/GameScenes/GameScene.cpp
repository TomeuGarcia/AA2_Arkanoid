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


	if (_player1->GetController()->GetButtonUp(ActionName::DOWN)) {
		for (std::list<Brick*>::const_iterator it = _bricks.begin(); it != _bricks.end(); ++it) {
			(*it)->NextSprite();
		}
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


	Vector2D<int> start(0, 0);
	Vector2D<int> size(36, 18);
	Vector2D<int> offset((800 / 2) - ((size.Y + 2) * (12.0f / 2.0f)),
						 40);

	std::list<BrickData> levelBricksData(gameData->GetLevelBricks());
	for (std::list<BrickData>::iterator it = levelBricksData.begin(); it != levelBricksData.end(); ++it) {	
		if (it->_brickType == BrickType::NORMAL) {
			_bricks.push_back(new NormalBrick(it->_x, it->_y, GetRandomBrickPoints(it->_brickType)));
		}
		else if (it->_brickType == BrickType::HEAVY) {
			_bricks.push_back(new HeavyBrick(it->_x, it->_y, GetRandomBrickPoints(it->_brickType)));
		}
		else if (it->_brickType == BrickType::FIX) {
			_bricks.push_back(new FixBrick(it->_x, it->_y));
		}


		start = (*_bricks.rbegin())->GetPosition();
		start.X = (start.X * size.Y);
		start.Y = (start.Y * size.X);

		(*_bricks.rbegin())->InitSprite(_renderer, start + offset, size);

	}

}

int GameScene::GetRandomBrickPoints(const BrickType& brickType)
{
	return (rand() % (_brickPoints[brickType].second - _brickPoints[brickType].first)) + _brickPoints[brickType].first;
}

void GameScene::InitBackgroundSprite()
{
	_backgroundSprite = new Image(_renderer, Vector2D<int>(0, 0), Vector2D<int>(800, 600), Vector2D<int>(0, 0), Vector2D<int>(800, 600));
	_backgroundSprite->Init("../../resources/Assets/Images/Background.jpg");
}

void GameScene::InitPlayerPlatforms()
{
	_player1->GetPlatform()->InitSprite(_renderer, Vector2D<int>(40, 300), Vector2D<int>(100, 320));
	_player2->GetPlatform()->InitSprite(_renderer, Vector2D<int>(720, 300), Vector2D<int>(780, 320));
}

