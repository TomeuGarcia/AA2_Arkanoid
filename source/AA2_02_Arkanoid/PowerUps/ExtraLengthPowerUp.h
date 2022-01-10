#pragma once
#include "PowerUp.h"


class ExtraLengthPowerUp : public PowerUp 
{
public:
	ExtraLengthPowerUp(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
		const Vector2D<float>& moveDirection, const float& moveSpeed, const float& sizeIncrease);

	virtual void DoEffect(Platform* platform) override;

private:
	float _sizeIncrease;

};