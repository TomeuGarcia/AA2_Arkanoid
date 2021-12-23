#pragma once
#include "../GameObjects/ImageGameObject.h"
#include "../GameObjects/TextGameObject.h"
#include "../Player/Platform.h"
#include "../Brick/NormalBrick.h"
#include "../Brick/HeavyBrick.h"
#include "../Brick/FixBrick.h"
#include "../Ball/Ball.h"
#include "../Wall/Wall.h"
#include "../Wall/ScoreWall.h"
#include "../Physics/CollissionManager.h"
#include <list>
#include <vector>

struct GameObjects {

	// Collision Manager
	CollisionManager* _collisionManager;

	// All
	std::vector<GameObject*> _gameObjectCollection;

	// Background
	ImageGameObject* _background;

	// Game 
	Platform* _platform1;
	Platform* _platform2;
	Ball* _ball;
	std::vector<Brick*> _bricks;

	// Score walls
	ScoreWall* _leftScoreWall;
	ScoreWall* _rightScoreWall;

	// Player
	TextGameObject* _scorePlayer1;
	TextGameObject* _scorePlayer2;
	TextGameObject* _scorePointsPlayer1;
	TextGameObject* _scorePointsPlayer2;
	std::vector<ImageGameObject*> _livesImagesPlayer1;
	std::vector<ImageGameObject*> _livesImagesPlayer2;


	GameObjects();
	GameObjects(CollisionManager* collisionManager);

	void Render() const;
	void Update(const double& elapsedTime);

	void AddGameObjectToCollection(GameObject* gameObject);
	void InitBackground(ImageGameObject* background);
	void InitPlatforms(Platform* platform1, Platform* platform2);
	void InitBall(Ball* ball);
	void AddBrick(Brick* newBrick);
	void InitWalls(Wall* topWall, Wall* bottomWall, ScoreWall* leftWall, ScoreWall* rightWall);

	void InitPlayerScores(TextGameObject* scorePlayer1, TextGameObject* scorePointsPlayer1,
		TextGameObject* scorePlayer2, TextGameObject* scorePointsPlayer2);
	void InitPlayersLives(SDL_Renderer* renderer, const char* path, const Vector2D<int>& size,
		const Vector2D<int>& sourcePosition, const Vector2D<int>& sourceSize);

	void UpdateScorePointsPlayer1(const char* points);
	void UpdateScorePointsPlayer2(const char* points);
	void Player1LosesLives();
	void Player2LosesLives();
};