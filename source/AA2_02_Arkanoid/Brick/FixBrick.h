#pragma once
#include "Brick.h"
class FixBrick:public Brick
{
public:
	FixBrick(const Vector2D<int>& position, const Vector2D<int>& size);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart) override;
	virtual void NextSprite() override;
};