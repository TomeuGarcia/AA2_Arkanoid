#pragma once
#include "SDL.h"
#include "CollisionsHelper.h"
#include "CollisionData.h"


//enum class ColliderType { NONE, SQUARE, CIRCLE, BOX, SPHERE, EDGE };
enum class ColliderType { NONE, SQUARE };

union ColliderBoundary 
{
	SDL_Rect _rectBoundary;
};



class Collider {

public: 
	Collider(ColliderType type);
	~Collider() = default;

	virtual bool IsCollidingWithCollider(const Collider* other) = 0;
	virtual bool WillBeCollidingWithColliderOnDirection(const Vector2D<float>& direction, const Collider* other) = 0;

	virtual void OnCollisionEnter();
	virtual void OnCollisionStay();
	virtual void OnCollisionExit();

	void SetCollisionData();

	ColliderType _type;
	ColliderBoundary _boundary;
	bool _willBeColliding;
	CollisionData _collisionData;
};