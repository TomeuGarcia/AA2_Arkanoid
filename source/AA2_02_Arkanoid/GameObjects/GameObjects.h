#pragma once
#include "../GameObjects/ImageGameObject.h"
#include "../GameObjects/TextGameObject.h"
#include "../Player/Platform.h"
#include "../Brick/NormalBrick.h"
#include "../Brick/HeavyBrick.h"
#include "../Brick/FixBrick.h"
#include "../Ball/Ball.h"
#include <list>
#include <vector>

struct GameObjects {

	ImageGameObject* _background;
	Platform* _platform1;
	Platform* _platform2;
	Ball* _ball;
	std::list<Brick*> _bricks;
	TextGameObject* _scorePlayer1;
	TextGameObject* _scorePlayer2;
	TextGameObject* _scorePointsPlayer1;
	TextGameObject* _scorePointsPlayer2;
	std::vector<ImageGameObject*> _livesPlayer1Image;
	std::vector<ImageGameObject*> _livesPlayer2Image;
	

	std::vector<GameObject*> _gameObjectCollection;

	GameObjects() 
		: _background(nullptr), _platform1(nullptr), _platform2(nullptr), _ball(nullptr), _bricks(), _gameObjectCollection(), 
		_scorePlayer1(nullptr), _scorePlayer2(nullptr), _livesPlayer1Image(),_livesPlayer2Image()
	{
	}
	void AddGameObjectToCollection(GameObject* gameObject) 
	{
		_gameObjectCollection.push_back(gameObject);
	}
	void InitBackground(ImageGameObject* background)
	{
		_background = background;
		AddGameObjectToCollection(background);
	}

	void InitPlatforms(Platform* platform1, Platform* platform2)
	{
		_platform1 = platform1;
		_platform2 = platform2;
		AddGameObjectToCollection(platform1);
		AddGameObjectToCollection(platform2);
	}

	void InitBall(Ball* ball)
	{
		_ball = ball;
		AddGameObjectToCollection(ball);
	}

	void AddBrick(Brick* newBrick) 
	{ 
		_bricks.push_back(newBrick); 
		AddGameObjectToCollection(newBrick);
	}
	void InitPlayerSocres(TextGameObject* scorePlayer1, TextGameObject* scorePointsPlayer1, 
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

	void InitPlayersLives(SDL_Renderer* renderer, const char* path, const Vector2D<int>& size,
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

	void UpdateScorePointsPlayer1(const char* points) {
		_scorePointsPlayer1->SetText(points);
		_scorePointsPlayer1->InitText();
	}

	void UpdateScorePointsPlayer2(const char* points) {
		_scorePointsPlayer2->SetText(points);
		_scorePointsPlayer2->InitText();
	}

	void Player1LosesLives() {
		delete *_livesPlayer1Image.rbegin();
		*_livesPlayer1Image.rbegin() = nullptr;
	}

	void Player2LosesLives() {
		delete* _livesPlayer2Image.rbegin();
		*_livesPlayer2Image.rbegin() = nullptr;
	}
};