#include "Rigidbody2D.h"

Rigidbody2D::Rigidbody2D(Collider* collider, Vector2D<float>* moveDirection)
	: _collider(collider), _moveDirection(moveDirection)
{
}

Rigidbody2D::~Rigidbody2D()
{
	_collider = nullptr;
	_moveDirection = nullptr;
}

void Rigidbody2D::Update(const Vector2D<float>* moveDirection)
{
	_moveDirection->X = moveDirection->X;
	_moveDirection->Y = moveDirection->Y;
}


void Rigidbody2D::SetWillBeColliding(const bool& willBeColliding) // Used by CollisionManager
{
	_collider->_willBeColliding = willBeColliding;
}

bool Rigidbody2D::WillBeColliding() const
{
	return _collider->_willBeColliding;
}

Collider* Rigidbody2D::GetCollider() const
{
	return _collider;
}

Vector2D<float> Rigidbody2D::GetMoveDirection() const
{
	return *_moveDirection;
}
