#include "PowerUp.h"

PowerUp::PowerUp(const Vector2D<float>& position, const Vector2D<int>& size, 
	const Vector2D<float>& moveDirection, const float& moveSpeed)
	: GameObject(Tag::POWER_UP, position, size), BoxCollider2D(this),
	_sprite(nullptr), _moveDirection(), _moveSpeed(moveSpeed)
{
	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };
}

void PowerUp::Update(const double& elapsedTime)
{
	Move(elapsedTime);
}

void PowerUp::Render() const
{
	_sprite->Draw();
}

void PowerUp::Move(const double& elapsedTime)
{
	_position += _moveDirection * _moveSpeed * elapsedTime;
	_sprite->SetDestinationStart(_position);
	SetBoundaryPosition(_position);
}
