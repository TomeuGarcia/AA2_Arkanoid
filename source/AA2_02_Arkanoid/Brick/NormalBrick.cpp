#include "NormalBrick.h"

NormalBrick::NormalBrick(const Vector2D<int>& position, const Vector2D<int>& size, const int& points) 
	: Brick(position, size, NORMAL_BRICK_SOURCE_WIDTH), _points(points) {}

void NormalBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart)
{
	_currentSprite = new Image(renderer, NORMAL_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, destinationStart, _size);
	_currentSprite->Init("../../resources/assets/images/bricks.png");
	_currentSprite->Rotate(90);
}

void NormalBrick::NextSprite()
{
	_currentSprite->SetSourceStart(_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
}