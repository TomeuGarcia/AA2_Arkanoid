#include "Player.h"

Player::Player(Controller* controller) : _controller(controller), _platform(nullptr)
{
}

Player::~Player()
{
	delete _controller;
}


void Player::InitPlatform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const float& moveSpeed)
{
	_platform = new Platform(renderer, position, size, moveSpeed);
}


Controller* Player::GetController() const
{
	return _controller;
}

Platform* Player::GetPlatform() const
{
	return _platform;
}

void Player::MovePlatform(const Vector2D<float>& direction, const double& elapsedTime)
{
	_platform->SetMoveDirection(direction);
	_platform->Move(elapsedTime);
}
