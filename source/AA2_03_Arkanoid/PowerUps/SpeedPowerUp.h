#pragma once
#include "PowerUp.h"


class SpeedPowerUp : public PowerUp
{
public:
	SpeedPowerUp(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
		const Vector2D<float>& moveDirection, const float& moveSpeed, const float& effectDuration,
		const float& speedIncrease);

	virtual void DoEffect(Platform* platform) override;

private:
	float _speedIncrease;
};