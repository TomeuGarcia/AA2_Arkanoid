#pragma once
#include "Brick.h"
#include "../Systems/LifeSystem.h"

class NormalBrick : public Brick {

public:
	NormalBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap,
		const int& points, const int& lives);
	~NormalBrick();

	virtual void Update(const double& elapsedTime) override;

private:
	virtual void GetsHit() override;
	void GetsDestroyed();

	int _points;
	LifeSystem _lifeSystem;
};