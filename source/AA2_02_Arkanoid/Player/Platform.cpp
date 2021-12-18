#include "Platform.h"

Platform::Platform() : _sprite(nullptr), _position(), _size(), _moveDistance(), _moveSpeed(), _collider() {}

Platform::~Platform()
{
	delete _sprite;
	delete _collider;
}

void Platform::Init(SDL_Renderer* renderer, const Vector2D<float>& destinationStart, const Vector2D<int>& destinationSize, const int& moveSpeed)
{
	_position = destinationStart;
	_size = Vector2D<int>(destinationSize.Y, destinationSize.X);
	_sprite = new Image(renderer, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE, Vector2D<int>(destinationStart.X, destinationStart.Y), destinationSize);
	_sprite->Init("../../resources/assets/images/platform.png");
	_sprite->Rotate(90);
	_moveSpeed = moveSpeed;
}

void Platform::InitCollider()
{
	_collider = new BoxCollider2D(SDL_Rect{ (int)_position.X, (int)_position.Y, _size.X, _size.Y });
}

void Platform::Draw() const
{
	_sprite->Draw();
}

void Platform::Move(const Vector2D<float>& direction, const float& elapsedTime)
{
	_position += direction * _moveSpeed * elapsedTime;

	_sprite->SetDestinationStart(_position);

	_collider->SetBoundaryPosition(_position);
}

BoxCollider2D* Platform::GetCollider() const
{
	return _collider;
}
