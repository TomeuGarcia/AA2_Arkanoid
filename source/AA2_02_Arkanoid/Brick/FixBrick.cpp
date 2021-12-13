#include "FixBrick.h"

FixBrick::FixBrick(const int& x, const int& y) : Brick(x,y, FIX_BRICK_SOURCE_WIDTH){}

void FixBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_currentSprite = new Image(renderer, FIX_BRICK_SOURCE_START, _spriteSize + FIX_BRICK_SOURCE_START, destinationStart, destinationEnd);
	_currentSprite->Init("../../resources/Assets/Images/bricks.png");
	_currentSprite->Rotate(90);
}

void FixBrick::NextSprite()
{
	Vector2D<int> sourceStart = (_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
	sourceStart %= FIX_BRICK_SOURCE_TOTAL_WIDTH;

	_currentSprite->SetSourceRect(sourceStart, _spriteSize);
}
