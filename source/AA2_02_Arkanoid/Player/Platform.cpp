#include "Platform.h"

Platform::Platform() : _sprite(nullptr), _position(), _size(), _moveDistance() {}

Platform::~Platform()
{
	delete _sprite;
}

void Platform::Init(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationSize)
{
	_position = destinationStart;
	_size = Vector2D<int>(destinationSize.Y, destinationSize.X);
	_sprite = new Image(renderer, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE, destinationStart, destinationSize);
	_sprite->Init("../../resources/assets/images/platform.png");
	_sprite->Rotate(90);
}

Image* Platform::GetSprite() const
{
	return _sprite;
}

void Platform::Move(const Vector2D<int>& direction, const float& speed)
{
	_moveDistance += speed;

	_position -= direction * _moveDistance;
	_sprite->SetDestinationStart(_position);

	if (_moveDistance >= 1.0f) _moveDistance = 0.0f;

}
