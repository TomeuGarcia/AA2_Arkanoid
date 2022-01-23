#include "SpeedPowerUp.h"

SpeedPowerUp::SpeedPowerUp(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
	const Vector2D<float>& moveDirection, const float& moveSpeed, const float& effectDuration,
	const float& speedIncrease)
	: PowerUp(position, size, moveDirection, moveSpeed, effectDuration, PowerUpType::EXTRA_SPEED),
	_speedIncrease(speedIncrease)
{
	// Initialize _sprite
	_sprite = new Image(renderer, POWERUP_SPEED_SOURCE_START, POWERUP_SOURCE_SIZE, Vector2D<int>(_position.X, _position.Y), _size);
	_sprite->Init("../../resources/assets/images/powerUps.png");
}

void SpeedPowerUp::DoEffect(Platform* platform)
{
	DoFinishEffect(platform);

	platform->SetMoveSpeed(platform->GetMoveSpeed() * _speedIncrease);

	NotifyPlayer(platform->GetPlayer());
}
