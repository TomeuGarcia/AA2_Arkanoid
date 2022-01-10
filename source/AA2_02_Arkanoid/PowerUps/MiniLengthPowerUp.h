#pragma once
#include "PowerUp.h"


class MiniLengthPowerUp : public PowerUp
{
public:
	MiniLengthPowerUp(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
		const Vector2D<float>& moveDirection, const float& moveSpeed, const float& sizeDecrease, const float& speedIncrease);

	virtual void DoEffect(Platform* platform) override;

private:
	float _sizeDecrease;
	float _speedIncrease;
};