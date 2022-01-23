#include "PowerUpFactory.h"

PowerUpFactory::PowerUpFactory()
{
}

PowerUpFactory::~PowerUpFactory()
{
}

PowerUp* PowerUpFactory::Create(const PowerUpType& powerUpType, SDL_Renderer* renderer, const Vector2D<float>& position, 
	const Vector2D<float>& moveDirection, PowerUpCreateData* powerUpCreateData)
{
	switch (powerUpType) {
	case PowerUpType::MINI_LENGTH:
		return new MiniLengthPowerUp(renderer, position, POWERUP_DESTINATION_SIZE, moveDirection, powerUpCreateData->_powerUpSpeed,
			powerUpCreateData->_powerUpDuration, powerUpCreateData->_sizeDecreasePercent);
		break;
	case PowerUpType::EXTRA_LENGTH:
		return new ExtraLengthPowerUp(renderer, position, POWERUP_DESTINATION_SIZE, moveDirection, powerUpCreateData->_powerUpSpeed,
			powerUpCreateData->_powerUpDuration, powerUpCreateData->_sizeIncreasePercent);
		break;
	case PowerUpType::EXTRA_SPEED:
		return new SpeedPowerUp(renderer, position, POWERUP_DESTINATION_SIZE, moveDirection, powerUpCreateData->_powerUpSpeed,
			powerUpCreateData->_powerUpDuration, powerUpCreateData->_speedIncreasePercent);
		break;
	default:
		break;
	}

	return nullptr;
}
