#pragma once
#include "../FileManaging/GameData.h"

class BrickFactory {

public:
	Brick* Create(const BrickData& brickData, std::map<BrickType, std::pair<int, int>>* brickPoints);
	int GetRandomBrickPoints(const BrickType& brickType, std::map<BrickType, std::pair<int, int>>* brickPoints);
};