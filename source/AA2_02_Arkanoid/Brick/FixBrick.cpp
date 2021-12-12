#include "FixBrick.h"

FixBrick::FixBrick(const int& x, const int& y, const int& points):Brick(x,y,points, 40){}

void FixBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 40), _spriteSize + Vector2D<int>(0, 40), destinationStart, destinationEnd);
	_currentSprite->Init("../../../resources/Assets/Images/bricks.jpg");
	_currentSprite->Rotate(90);
}

void FixBrick::NextSprite()
{
	Vector2D<int> currentSourceStart = _currentSprite->GetSourceRectStart();

	Vector2D<int> start = currentSourceStart + Vector2D<int>(_spriteSourceWidth, 0);
	start %= 200;
	Vector2D<int> end = currentSourceStart + _spriteSize + Vector2D<int>(_spriteSourceWidth, 0);
	end %= 200;

	_currentSprite->SetSourceRect(start, end);
}
