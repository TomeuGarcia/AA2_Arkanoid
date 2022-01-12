#pragma once
#include "ExtraLengthPowerUp.h"
#include "MiniLengthPowerUp.h"

class PowerUpFactory {

public:
	PowerUp* Create(PowerUpType powerUpType, SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
		const Vector2D<float>& moveDirection, const float& moveSpeed, const float& sizeDecrease, const float& speedIncrease);
};