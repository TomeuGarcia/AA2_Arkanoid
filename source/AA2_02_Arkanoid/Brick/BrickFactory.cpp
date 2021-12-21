#include "BrickFactory.h"


Brick* BrickFactory::Create(SDL_Renderer* renderer, const BrickData& brickData, const Vector2D<float>& rotatedSize, const Vector2D<float>& offset,
	std::map<BrickType, std::pair<int, int>>* brickPoints)
{
	Vector2D<float> brickPosition(brickData._x, brickData._y);
	brickPosition *= rotatedSize;
	brickPosition += offset;

	if (brickData._brickType == BrickType::NORMAL) {
		return new NormalBrick(renderer, brickPosition, BRICK_DESTINATION_SIZE, NORMAL_BRICK_SOURCE_WIDTH_GAP, 
			GetRandomBrickPoints(brickData._brickType, brickPoints), NORMAL_BRICK_LIVES);
	}
	else if (brickData._brickType == BrickType::HEAVY) {
		return new HeavyBrick(renderer, brickPosition, BRICK_DESTINATION_SIZE, HEAVY_BRICK_SOURCE_WIDTH_GAP, 
			GetRandomBrickPoints(brickData._brickType, brickPoints), HEAVY_BRICK_LIVES);
	}
	else if (brickData._brickType == BrickType::FIX) {
		return new FixBrick(renderer, brickPosition, BRICK_DESTINATION_SIZE, FIX_BRICK_SOURCE_WIDTH_GAP);
	}
}


int BrickFactory::GetRandomBrickPoints(const BrickType& brickType, std::map<BrickType, std::pair<int, int>>* brickPoints)
{
	return (rand() % ((*brickPoints)[brickType].second - (*brickPoints)[brickType].first)) + (*brickPoints)[brickType].first;
}
