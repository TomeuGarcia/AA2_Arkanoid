#include "HeavyBrick.h"

HeavyBrick::HeavyBrick(const int& x, const int& y, const int& points) : Brick(x, y, 40), _points(points) {}

void HeavyBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 20), _spriteSize, destinationStart, destinationEnd);
	_currentSprite->Init("../../resources/Assets/Images/bricks.png");
	_currentSprite->Rotate(90);
}

void HeavyBrick::NextSprite()
{
	_currentSprite->SetSourceRect(_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0), _spriteSize);
}
