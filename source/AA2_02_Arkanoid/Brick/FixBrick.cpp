#include "FixBrick.h"

FixBrick::FixBrick(const Vector2D<int>& position, const Vector2D<int>& size) : Brick(position, size, FIX_BRICK_SOURCE_WIDTH){}

void FixBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart)
{
	_currentSprite = new Image(renderer, FIX_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, destinationStart, _size);
	_currentSprite->Init("../../resources/Assets/Images/bricks.png");
	_currentSprite->Rotate(90);
}

void FixBrick::NextSprite()
{
	Vector2D<int> sourceStart = (_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
	sourceStart %= FIX_BRICK_SOURCE_TOTAL_WIDTH;

	_currentSprite->SetSourceStart(sourceStart);
}
