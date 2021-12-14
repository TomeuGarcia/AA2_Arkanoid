#include "BrickFactory.h"


BrickFactory::BrickFactory(std::map<BrickType, std::pair<int, int>> brickPoints) : _brickPoints(brickPoints) {}

Brick* BrickFactory::Create(const BrickData& brickData)
{
	if (brickData._brickType == BrickType::NORMAL) {
		return new NormalBrick(Vector2D<int>(brickData._x, brickData._y), BRICK_DESTINATION_SIZE, GetRandomBrickPoints(brickData._brickType));
	}
	else if (brickData._brickType == BrickType::HEAVY) {
		return new HeavyBrick(Vector2D<int>(brickData._x, brickData._y), BRICK_DESTINATION_SIZE, GetRandomBrickPoints(brickData._brickType));
	}
	else if (brickData._brickType == BrickType::FIX) {
		return new FixBrick(Vector2D<int>(brickData._x, brickData._y), BRICK_DESTINATION_SIZE);
	}
}


int BrickFactory::GetRandomBrickPoints(const BrickType& brickType)
{
	return (rand() % (_brickPoints[brickType].second - _brickPoints[brickType].first)) + _brickPoints[brickType].first;
}
