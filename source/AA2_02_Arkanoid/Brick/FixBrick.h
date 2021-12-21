#pragma once
#include "Brick.h"
class FixBrick: public Brick {

public:
	FixBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap);
	~FixBrick();

	virtual void NextSprite() override;
	virtual bool DoCollision() override;
};