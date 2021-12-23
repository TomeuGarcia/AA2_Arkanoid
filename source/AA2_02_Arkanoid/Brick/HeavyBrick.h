#pragma once
#include "Brick.h"
#include "../Systems/LifeSystem.h"

class HeavyBrick : public Brick {

public:
	HeavyBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap,
		const int& points, const int& lives);
	~HeavyBrick();

	virtual void NextSprite() override;
	virtual void GetsHit() override;

private:
	void GetsDestroyed();

	int _points;
	LifeSystem _lifeSystem;
};