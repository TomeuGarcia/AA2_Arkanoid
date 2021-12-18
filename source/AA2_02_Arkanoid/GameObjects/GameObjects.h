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

	std::vector<GameObject*> _gameObjectCollection;

	GameObjects() : _background(nullptr), _platform1(nullptr), _platform2(nullptr), _ball(nullptr), _bricks(), _gameObjectCollection()
	{
	}

	void InitBackground(ImageGameObject* background)
	{
		_background = background;
		_gameObjectCollection.push_back(background);
	}

	void InitPlatforms(Platform* platform1, Platform* platform2)
	{
		_platform1 = platform1;
		_platform2 = platform2;
		_gameObjectCollection.push_back(platform1);
		_gameObjectCollection.push_back(platform2);
	}

	void InitBall(Ball* ball)
	{
		_ball = ball;
		_gameObjectCollection.push_back(ball);
	}

	void AddBrick(Brick* newBrick) 
	{ 
		_bricks.push_back(newBrick); 
		_gameObjectCollection.push_back(newBrick);
	}
};