#pragma once
#include "Brick.h"
#include "../Systems/LifeSystem.h"

class HeavyBrick :public Brick
{
public:
	HeavyBrick(const Vector2D<int>& position, const Vector2D<int>& size, const int& points);
	~HeavyBrick();

	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart) override;
	virtual void NextSprite() override;
	virtual bool DoCollision() override;

private:
	int _points;
	LifeSystem _lifeSystem;
};