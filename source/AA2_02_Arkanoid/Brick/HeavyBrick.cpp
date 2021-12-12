#include "HeavyBrick.h"

HeavyBrick::HeavyBrick(const int& x, const int& y, const int& points) :Brick(x, y, points) {}

void HeavyBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destination)
{
	_currentSprite = new Image(renderer, Vector2D<int>(0, 20), Vector2D<int>(40, 20), destination, destination + Vector2D<int>(40, 20));
	_currentSprite->Init("../../../resources/Assets/Images/bricks.jpg");
}
