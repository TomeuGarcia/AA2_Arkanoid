#pragma once
#include <iostream>
#include "Collider.h"

class BoxCollider2D : public Collider {

public:
	BoxCollider2D();
	BoxCollider2D(GameObject* thisGameObject);
	BoxCollider2D(GameObject* thisGameObject, const SDL_Rect& rectBoundary);

	~BoxCollider2D();

	virtual bool IsCollidingWithCollider(const Collider* other) override;
	virtual bool WillBeCollidingWithColliderOnDirection(const Vector2D<float>& direction, const Collider* other) override;

	void SetBoundaryPosition(const Vector2D<float>& boundaryPosition);
	void SetBoundarySize(const Vector2D<int>& boundarySize);

};