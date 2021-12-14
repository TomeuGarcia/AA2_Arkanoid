#include "HeavyBrick.h"

HeavyBrick::HeavyBrick(const Vector2D<int>& position, const Vector2D<int>& size, const int& points) 
	: Brick(position, size, HEAVY_BRICK_SOURCE_WIDTH), _points(points) {}

void HeavyBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 20), _spriteSourceSize, destinationStart, _size);
	_currentSprite->Init("../../resources/Assets/Images/bricks.png");
	_currentSprite->Rotate(90);
}

void HeavyBrick::NextSprite()
{
	//_currentSprite->SetSourceRect(_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0), _spriteSourceSize);
	_currentSprite->SetSourceStart(_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
}
