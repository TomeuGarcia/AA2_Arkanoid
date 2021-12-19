#pragma once
#include "../GameObjects/ImageGameObject.h"
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
	std::vector<ImageGameObject*> _livePlayer1Image;
	std::vector<ImageGameObject*> _livePlayer2Image;
	

	std::vector<GameObject*> _gameObjectCollection;

	GameObjects() : _background(nullptr), _platform1(nullptr), _platform2(nullptr), _ball(nullptr), _bricks(), _gameObjectCollection(), _scorePlayer1(nullptr), _scorePlayer2(nullptr),
		_livePlayer1Image(),_livePlayer2Image()
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
	void InitPlayerSocres(TextGameObject* pl1, TextGameObject* pl2) 
	{
		_scorePlayer1 = pl1;
		_scorePlayer2 = pl2;
		AddGameObjectToCollection(pl1);
		AddGameObjectToCollection(pl2);
	}
	void InitPlayersLives(ImageGameObject* livesImage) 
	{
		for (int i = 0; i < 3; ++i) 
		{
			_livePlayer1Image.push_back(new ImageGameObject(livesImage));
			_livePlayer2Image.push_back(new ImageGameObject(livesImage));
			_livePlayer1Image[i]->SetImagePosition(Vector2D<int>(100 + (i * 40), 550));
			_livePlayer2Image[i]->SetImagePosition(Vector2D<int>(400 + (i * 40), 550)); 
			AddGameObjectToCollection(_livePlayer1Image[i]);
			AddGameObjectToCollection(_livePlayer2Image[i]);
		}
	}
};