#pragma once
#include <iostream>
#include <list>
#include <map>

#include "../Brick/FixBrick.h"
#include "../Brick/HeavyBrick.h"
#include "../Brick/NormalBrick.h"

#include "../Physics/Vector2D.h"


enum class BrickType {NORMAL, HEAVY, FIX};

struct BrickData {
	BrickData(const BrickType& brickType, const int& i, const int& j);

	BrickType _brickType;
	int _x;
	int _y;
};


enum class PowerUpType { EXTRA_LENGTH, MINI_LENGTH };

struct PowerUpData {


	BrickType _brickType;
};



class GameData {

public:
	GameData();
	void SetBrickInfo(std::string& brickType, const int& min, const int& max);
	void SetPlatformSpeed(const int& platformSpeed);
	void SetBallSpeed(const int& ballSpeed);
	void SetLevelBricks(const int& i, const int& j, std::string& type);

	int GetPlatformSpeed();
	int GetBallSpeed();
	std::list<BrickData> GetLevelBricks();
	std::map<BrickType, std::pair<int, int>> GetBrickPoints();

private:
	int _platformSpeed;
	int _ballSpeed;
	std::list<BrickData> _levelBricks;
	std::map<BrickType, std::pair<int, int>> _brickPoints;

	std::map<std::string, BrickType> _brickStringToBrickType;
};