#pragma once
#include "Brick.h"
#include "../Systems/LifeSystem.h"

class NormalBrick : public Brick {

public:
	NormalBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap,
		const int& points, const int& lives);
	~NormalBrick();

	virtual void NextSprite() override;
	virtual bool DoCollision() override;

private:
	int _points;
	LifeSystem _lifeSystem;
};