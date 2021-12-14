#include "NormalBrick.h"

NormalBrick::NormalBrick(const Vector2D<int>& position, const Vector2D<int>& size, const int& points) 
	: Brick(position, size, 80), _points(points) {}

void NormalBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 0), _spriteSourceSize + Vector2D<int>(0, 0), destinationStart, _size);
	_currentSprite->Init("../../resources/Assets/Images/bricks.png");
	_currentSprite->Rotate(90);
}

void NormalBrick::NextSprite()
{
	//_currentSprite->SetSourceRect(_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0), _spriteSourceSize);
	_currentSprite->SetSourceStart(_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
}