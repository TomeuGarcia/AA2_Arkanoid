#pragma once
#include "Brick.h"
class FixBrick:public Brick
{
public:
	FixBrick(const int& x, const int& y, const int& points);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destination) override;
};