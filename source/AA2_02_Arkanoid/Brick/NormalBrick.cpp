#include "NormalBrick.h"

NormalBrick::NormalBrick(const int& x, const int& y, const int& points) :Brick(x, y, 80), _points(points) {}

void NormalBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 0), _spriteSize + Vector2D<int>(0, 0), destinationStart, destinationEnd);
	_currentSprite->Init("../../resources/Assets/Images/bricks.jpg");
	//_currentSprite->Rotate(90);
}

void NormalBrick::NextSprite()
{
	Vector2D<int> currentSourceStart = _currentSprite->GetSourceRectStart();

	_currentSprite->SetSourceRect(currentSourceStart + Vector2D<int>(_spriteSourceWidth, 0),
		currentSourceStart + _spriteSize + Vector2D<int>(_spriteSourceWidth, 0));
}