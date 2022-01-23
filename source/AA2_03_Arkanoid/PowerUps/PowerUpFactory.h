#pragma once
#include "../FileManaging/GameData.h"
#include "ExtraLengthPowerUp.h"
#include "MiniLengthPowerUp.h"
#include "SpeedPowerUp.h"

class PowerUpFactory {

public:
	PowerUpFactory();
	~PowerUpFactory();

	PowerUp* Create(const PowerUpType& powerUpType, SDL_Renderer* renderer, const Vector2D<float>& position,
		const Vector2D<float>& moveDirection, PowerUpCreateData* powerUpCreateData);
};