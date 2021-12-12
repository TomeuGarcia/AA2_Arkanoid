#pragma once
#include "Brick.h"
class NormalBrick :public Brick
{
public:
	NormalBrick(const int& x, const int& y, const int& points);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destination) override;
};