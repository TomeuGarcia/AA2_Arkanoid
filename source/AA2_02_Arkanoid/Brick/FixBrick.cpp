#include "FixBrick.h"

FixBrick::FixBrick(const int& x, const int& y) : Brick(x,y, 40){}

void FixBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 40), _spriteSize + Vector2D<int>(0, 40), destinationStart, destinationEnd);
	_currentSprite->Init("../../resources/Assets/Images/bricks.png");
	_currentSprite->Rotate(90);
}

void FixBrick::NextSprite()
{
	Vector2D<int> sourceStart = (_currentSprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
	sourceStart %= 200;

	_currentSprite->SetSourceRect(sourceStart, _spriteSize);
}
