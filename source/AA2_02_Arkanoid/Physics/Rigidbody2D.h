#pragma once
#include <iostream>
#include "BoxCollider2D.h"


class Rigidbody2D 
{
public:
	Rigidbody2D(Collider* collider, Vector2D<float>* moveDirection);
	~Rigidbody2D();

	void Update(const Vector2D<float>* moveDirection);

	void SetWillBeColliding(const bool& willBeColliding);
	bool WillBeColliding() const;
	Collider* GetCollider() const;
	Vector2D<float> GetMoveDirection() const;

private:
	Collider* _collider;
	Vector2D<float>* _moveDirection;
	bool _willBeColliding;
};