#pragma once
#include "BoxCollider2D.h"


class Rigidbody2D 
{
public:
	Rigidbody2D(Collider* collider, Vector2D<float>* moveDirection);
	~Rigidbody2D();

	void UpdateColliderBoundary();
	void SetWillBeColliding(const bool& willBeColliding);
	bool WillBeColliding() const;
	Collider* GetCollider() const;

private:
	Collider* _collider;
	Vector2D<float>* _moveDirection;
	ColliderBoundary _colliderBoundary;
	bool _willBeColliding;
};