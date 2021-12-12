#include "HeavyBrick.h"

HeavyBrick::HeavyBrick(const int& x, const int& y, const int& points) :Brick(x, y, points, 40) {}

void HeavyBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 20), _spriteSize + Vector2D<int>(0, 20), destinationStart, destinationEnd);
	_currentSprite->Init("../../../resources/Assets/Images/bricks.jpg");
	_currentSprite->Rotate(90);
}

void HeavyBrick::NextSprite()
{
	Vector2D<int> currentSourceStart = _currentSprite->GetSourceRectStart();

	_currentSprite->SetSourceRect(currentSourceStart + Vector2D<int>(_spriteSourceWidth, 0),
		currentSourceStart + _spriteSize + Vector2D<int>(_spriteSourceWidth, 0));
}
