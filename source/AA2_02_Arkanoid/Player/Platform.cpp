#include "Platform.h"

Platform::Platform() : _sprite(nullptr), _position(), _size(), _moveDistance(), _moveSpeed() {}

Platform::~Platform()
{
	delete _sprite;
}

void Platform::Init(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationSize, const int& moveSpeed)
{
	_position = destinationStart;
	_size = Vector2D<int>(destinationSize.Y, destinationSize.X);
	_sprite = new Image(renderer, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE, destinationStart, destinationSize);
	_sprite->Init("../../resources/assets/images/platform.png");
	_sprite->Rotate(90);
	_moveSpeed = moveSpeed;
}

void Platform::Draw() const
{
	_sprite->Draw();
}

void Platform::Move(const Vector2D<int>& direction, const float& elapsedTime)
{
	_moveDistance += _moveSpeed * elapsedTime;

	_position += Vector2D<int>(direction.X, -direction.Y) * _moveDistance;
	_sprite->SetDestinationStart(_position);

	if (_moveDistance >= 1.0f) _moveDistance = 0.0f;

}
