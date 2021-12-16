#pragma once
#include "../Player/Player.h"
#include "../Brick/NormalBrick.h"
#include "../Brick/HeavyBrick.h"
#include "../Brick/FixBrick.h"
#include "../Ball/Ball.h"

struct GameObjects {

	Player* _player1;
	Player* _player2;
	std::list<Brick*> _bricks;
	Ball* _ball;
	Image* _background;

	GameObjects() : _player1(nullptr), _player2(nullptr), _bricks(), _ball(nullptr), _background(nullptr) 
	{		
	}
	void AddNewBrick(Brick* newBrick) { _bricks.push_back(newBrick); }

};