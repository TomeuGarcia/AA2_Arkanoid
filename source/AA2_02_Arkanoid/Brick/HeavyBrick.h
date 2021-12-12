#pragma once
#include "Brick.h"
class HeavyBrick :public Brick
{
public:
	HeavyBrick(const int& x, const int& y, const int& points);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd) override;
	virtual void NextSprite() override;

private:
	int _points;

};