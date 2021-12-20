#pragma once
#include "Collider.h"

class BoxCollider2D : public Collider {

public:
	BoxCollider2D();
	BoxCollider2D(const SDL_Rect& boundaries);
	~BoxCollider2D();

	virtual bool IsCollidingWithCollider(const Collider* other) override;
	virtual ColliderBoundary BoundaryInDirection(const Vector2D<float> direction) override;

	void SetBoundaryPosition(const Vector2D<float>& boundaryPosition);
	void SetBoundarySize(const Vector2D<int>& boundarySize);

};