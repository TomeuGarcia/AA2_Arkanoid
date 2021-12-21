#include "GameObjects.h"

GameObjects::GameObjects() 
	: _collisionManager(nullptr), _gameObjectCollection(), _background(nullptr),
	_platform1(nullptr), _platform2(nullptr), _ball(nullptr),
	_scorePlayer1(nullptr), _scorePlayer2(nullptr), _scorePointsPlayer1(nullptr), _scorePointsPlayer2(nullptr),
	_livesPlayer1Image(), _livesPlayer2Image()
{}

GameObjects::GameObjects(CollisionManager* collisionManager)
	: _collisionManager(collisionManager), _gameObjectCollection(), _background(nullptr),
	_platform1(nullptr), _platform2(nullptr), _ball(nullptr),
	_scorePlayer1(nullptr), _scorePlayer2(nullptr), _scorePointsPlayer1(nullptr), _scorePointsPlayer2(nullptr),
	_livesPlayer1Image(), _livesPlayer2Image()
{}


void GameObjects::Render() const {

	for (int i{ 0 }; i < _gameObjectCollection.size(); ++i) {
		if (_gameObjectCollection[i]->IsActive()) {
			_gameObjectCollection[i]->Render();
		}
	}
}

void GameObjects::Update(const double& elapsedTime) {
	for (int i{ 0 }; i < _gameObjectCollection.size(); ++i) {
		if (_gameObjectCollection[i]->IsActive()) {
			_gameObjectCollection[i]->Update(elapsedTime);
		}
	}
}


void GameObjects::AddGameObjectToCollection(GameObject* gameObject)
{
	_gameObjectCollection.push_back(gameObject);
}

void GameObjects::InitBackground(ImageGameObject* background)
{
	_background = background;
	AddGameObjectToCollection(_background);
}

void GameObjects::InitPlatforms(Platform* platform1, Platform* platform2)
{
	_platform1 = platform1;
	_platform2 = platform2;
	AddGameObjectToCollection(platform1);
	AddGameObjectToCollection(platform2);

	_collisionManager->AddGameObjectRigidbody(platform1->GetRigidbody());
	_collisionManager->AddGameObjectRigidbody(platform2->GetRigidbody());
}

void GameObjects::InitBall(Ball* ball)
{
	_ball = ball;
	AddGameObjectToCollection(ball);

	_collisionManager->AddGameObjectRigidbody(_ball->GetRigidbody());
}

void GameObjects::AddBrick(Brick* newBrick)
{
	_bricks.push_back(newBrick);
	AddGameObjectToCollection(newBrick);

	_collisionManager->AddRigidbodylessGameObjectCollider(newBrick);
}

void GameObjects::InitWalls(Wall* topWall, Wall* bottomWall, Wall* leftWall, Wall* rightWall) {
	AddGameObjectToCollection(topWall);
	AddGameObjectToCollection(bottomWall);
	AddGameObjectToCollection(leftWall);
	AddGameObjectToCollection(rightWall);

	_collisionManager->AddRigidbodylessGameObjectCollider(topWall);
	_collisionManager->AddRigidbodylessGameObjectCollider(bottomWall);
	_collisionManager->AddRigidbodylessGameObjectCollider(leftWall);
	_collisionManager->AddRigidbodylessGameObjectCollider(rightWall);
}

void GameObjects::InitPlayerScores(TextGameObject* scorePlayer1, TextGameObject* scorePointsPlayer1,
	TextGameObject* scorePlayer2, TextGameObject* scorePointsPlayer2)
{
	_scorePlayer1 = scorePlayer1;
	_scorePointsPlayer1 = scorePointsPlayer1;
	AddGameObjectToCollection(scorePlayer1);
	AddGameObjectToCollection(scorePointsPlayer1);

	_scorePlayer2 = scorePlayer2;
	_scorePointsPlayer2 = scorePointsPlayer2;
	AddGameObjectToCollection(scorePlayer2);
	AddGameObjectToCollection(scorePointsPlayer2);
}

void GameObjects::InitPlayersLives(SDL_Renderer* renderer, const char* path, const Vector2D<int>& size,
	const Vector2D<int>& sourcePosition, const Vector2D<int>& sourceSize)
{
	for (int i = 0; i < 3; ++i)
	{
		_livesPlayer1Image.push_back(new ImageGameObject(renderer, path, Vector2D<int>(100 + (i * 80), 550),
			size, sourcePosition, sourceSize));
		_livesPlayer2Image.push_back(new ImageGameObject(renderer, path, Vector2D<int>(480 + (i * 80), 550),
			size, sourcePosition, sourceSize));
		AddGameObjectToCollection(_livesPlayer1Image[i]);
		AddGameObjectToCollection(_livesPlayer2Image[i]);
	}
}

void GameObjects::UpdateScorePointsPlayer1(const char* points) {
	_scorePointsPlayer1->SetText(points);
	_scorePointsPlayer1->InitText();
}

void GameObjects::UpdateScorePointsPlayer2(const char* points) {
	_scorePointsPlayer2->SetText(points);
	_scorePointsPlayer2->InitText();
}

void GameObjects::Player1LosesLives() {
	ImageGameObject** holder = &(*_livesPlayer1Image.rbegin());
	ImageGameObject* holder2 = *_livesPlayer1Image.rbegin();
	delete holder2;
	*holder = nullptr;

	/*std::list<ImageGameObject*>::reverse_iterator itHolder = _livesPlayer1Image.rbegin();
	*_livesPlayer1Image.rbegin().base() = nullptr;
	delete (*itHolder);*/
}

void GameObjects::Player2LosesLives() {
	/*std::list<ImageGameObject*>::reverse_iterator itHolder = _livesPlayer2Image.rbegin();
	*_livesPlayer2Image.rbegin().base() = nullptr;
	delete (*itHolder);*/
}