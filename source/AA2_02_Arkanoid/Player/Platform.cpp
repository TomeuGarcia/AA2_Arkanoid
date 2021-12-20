#include "Platform.h"

Platform::Platform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const float& moveSpeed)
	: _sprite(nullptr), _collider(nullptr), _rigidbody(nullptr), _position(position), _size(size), 
	_moveDirection(Vector2D<float>(0,0)), _moveSpeed(moveSpeed)
{
	// Initialize _sprite
	_sprite = new Image(renderer, Vector2D<int>(0, 0), PLATFORM_SOURCE_SIZE, Vector2D<int>(_position.X, _position.Y), _size);
	_sprite->Init("../../resources/assets/images/platform.png");
	_sprite->Rotate(90);

	// Initialize _collider
	_collider = new BoxCollider2D({ (int)_position.X, (int)_position.Y, _size.Y, _size.X }); // Size inverted due to 90deg rotation

	// Initialize _rigidbody
	_rigidbody = new Rigidbody2D(_collider, &_moveDirection);
}

Platform::~Platform()
{
	delete _sprite;
	delete _collider;
	delete _rigidbody;
}


void Platform::Update(const double& elapsedTime)
{
	if (!_rigidbody->WillBeColliding()) {
		Move(elapsedTime);
	}
	_collider->SetBoundaryPosition(_position);
}

void Platform::Render() const
{
	_sprite->Draw();
}


void Platform::Move(const float& elapsedTime)
{
	_position += _moveDirection * _moveSpeed * elapsedTime;
	_sprite->SetDestinationStart(_position);
}

void Platform::SetMoveDirection(const Vector2D<float>& direction)
{
	//_moveDirection = direction;
	_moveDirection.X = direction.X;
	_moveDirection.Y = direction.Y;
}

BoxCollider2D* Platform::GetCollider() const
{
	return _collider;
}

Rigidbody2D* Platform::GetRigidbody() const
{
	return _rigidbody;
}
