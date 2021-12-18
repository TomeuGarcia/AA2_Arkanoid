#pragma once
#include "../FileManaging/GameData.h"

class BrickFactory {

public:
	Brick* Create(SDL_Renderer* renderer, const BrickData& brickData, const Vector2D<int>& rotatedSize, const Vector2D<int>& offset,
		std::map<BrickType, std::pair<int, int>>* brickPoints);
	int GetRandomBrickPoints(const BrickType& brickType, std::map<BrickType, std::pair<int, int>>* brickPoints);
};