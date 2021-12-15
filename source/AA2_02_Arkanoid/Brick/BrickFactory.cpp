#include "BrickFactory.h"


Brick* BrickFactory::Create(const BrickData& brickData, std::map<BrickType, std::pair<int, int>>* brickPoints)
{
	if (brickData._brickType == BrickType::NORMAL) {
		return new NormalBrick(Vector2D<int>(brickData._x, brickData._y), BRICK_DESTINATION_SIZE, GetRandomBrickPoints(brickData._brickType, brickPoints));
	}
	else if (brickData._brickType == BrickType::HEAVY) {
		return new HeavyBrick(Vector2D<int>(brickData._x, brickData._y), BRICK_DESTINATION_SIZE, GetRandomBrickPoints(brickData._brickType, brickPoints));
	}
	else if (brickData._brickType == BrickType::FIX) {
		return new FixBrick(Vector2D<int>(brickData._x, brickData._y), BRICK_DESTINATION_SIZE);
	}
}


int BrickFactory::GetRandomBrickPoints(const BrickType& brickType, std::map<BrickType, std::pair<int, int>>* brickPoints)
{
	return (rand() % ((*brickPoints)[brickType].second - (*brickPoints)[brickType].first)) + (*brickPoints)[brickType].first;
}
