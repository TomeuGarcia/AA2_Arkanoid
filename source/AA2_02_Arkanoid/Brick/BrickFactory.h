#pragma once
#include "../FileManaging/GameData.h"

class BrickFactory {

public:
	BrickFactory(std::map<BrickType, std::pair<int, int>> brickPoints);
	Brick* Create(const BrickData& brickData);
	int GetRandomBrickPoints(const BrickType& brickType);

private:
	std::map<BrickType, std::pair<int, int>> _brickPoints;
};