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

	return false;
}

void GameScene::Render() const
{
	std::cout << "GameGameScene::Render\n";

	SDL_RenderClear(_renderer);

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
	int xIncrement{40};
	int yIncrement{20};
	Vector2D<int> end(xIncrement, yIncrement);

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
		start.X = start.X * 40;
		start.Y = start.Y * 40;
		end = start + Vector2D<int>(40,20);
		end.X;
		end.Y;
		(*_bricks.rbegin())->InitSprite(_renderer, start, end);

	}

}

int GameScene::GetRandomBrickPoints(const BrickType& brickType)
{
	return (rand() % (_brickPoints[brickType].second - _brickPoints[brickType].first)) + _brickPoints[brickType].first;
}

