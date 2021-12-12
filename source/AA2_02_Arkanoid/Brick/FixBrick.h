#pragma once
#include "Brick.h"
class FixBrick:public Brick
{
public:
	FixBrick(const int& x, const int& y);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd) override;
	virtual void NextSprite() override;
};