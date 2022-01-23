#include "ExtraLengthPowerUp.h"

ExtraLengthPowerUp::ExtraLengthPowerUp(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
	const Vector2D<float>& moveDirection, const float& moveSpeed, const float& effectDuration, const float& sizeIncrease)
	: PowerUp(position, size, moveDirection, moveSpeed, effectDuration, PowerUpType::EXTRA_LENGTH), _sizeIncrease(sizeIncrease)
{
	// Initialize _sprite
	_sprite = new Image(renderer, POWERUP_EXTRA_SOURCE_START, POWERUP_SOURCE_SIZE, Vector2D<int>(_position.X, _position.Y), _size);
	_sprite->Init("../../resources/assets/images/powerUps.png");
}

void ExtraLengthPowerUp::DoEffect(Platform* platform)
{
	DoFinishEffect(platform);

	Vector2D<float> platformSize(platform->GetSizeFloat());
	platformSize.Y *= _sizeIncrease;
	platform->SetSize(platformSize);

	NotifyPlayer(platform->GetPlayer());
}
