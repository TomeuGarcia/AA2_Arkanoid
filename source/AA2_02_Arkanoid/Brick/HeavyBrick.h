#pragma once
#include "Brick.h"

class HeavyBrick :public Brick
{
public:
	HeavyBrick(const Vector2D<int>& position, const Vector2D<int>& size, const int& points);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart) override;
	virtual void NextSprite() override;

private:
	int _points;

};