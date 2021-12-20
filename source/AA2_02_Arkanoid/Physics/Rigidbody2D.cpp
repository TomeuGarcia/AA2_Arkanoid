#include "Rigidbody2D.h"

Rigidbody2D::Rigidbody2D(Collider* collider, Vector2D<float>* moveDirection)
	: _collider(collider), _moveDirection(moveDirection), _willBeColliding(false)
{
	_colliderBoundary = _collider->_boundary;
}

Rigidbody2D::~Rigidbody2D()
{
	_collider = nullptr;
	_moveDirection = nullptr;
}


void Rigidbody2D::UpdateColliderBoundary()
{
	_colliderBoundary = _collider->BoundaryInDirection(*_moveDirection);	
}

void Rigidbody2D::SetWillBeColliding(const bool& willBeColliding) // Used by CollisionManager
{
	_willBeColliding = willBeColliding;
}

bool Rigidbody2D::WillBeColliding() const
{
	return _willBeColliding;
}

Collider* Rigidbody2D::GetCollider() const
{
	return _collider;
}
