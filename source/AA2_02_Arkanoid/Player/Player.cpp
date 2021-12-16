#include "Player.h"

Player::Player(Controller* controller) : _controller(controller), _platform(nullptr)
{
	_platform = new Platform;
}

Player::~Player()
{
	delete _controller;
}

Controller* Player::GetController() const
{
	return _controller;
}

Platform* Player::GetPlatform() const
{
	return _platform;
}

void Player::MovePlatform(const Vector2D<float>& direction, const float& speed)
{
	_platform->Move(direction, speed);
}
