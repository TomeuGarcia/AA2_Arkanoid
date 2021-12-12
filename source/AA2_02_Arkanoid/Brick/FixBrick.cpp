#include "FixBrick.h"

FixBrick::FixBrick(const int& x, const int& y, const int& points):Brick(x,y,points){}

void FixBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destination)
{
	_currentSprite = new Image(renderer,Vector2D<int>(0,40), Vector2D<int>(_spriteWidth,0) + Vector2D<int>(0, 60),destination,destination + Vector2D<int>(40,20));
	_currentSprite->Init("../../../resources/Assets/Images/bricks.jpg");
}
