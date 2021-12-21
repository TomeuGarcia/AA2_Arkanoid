#pragma once
#include "SDL.h"
#include "CollisionsHelper.h"
#include "CollisionData.h"
#include "../GameObjects/GameObject.h"


//enum class ColliderType { NONE, SQUARE, CIRCLE, BOX, SPHERE, EDGE };
enum class ColliderType { NONE, SQUARE };

union ColliderBoundary 
{
	SDL_Rect _rectBoundary;
};



class Collider {

public: 
	Collider(GameObject* thisGameObject, ColliderType type);
	~Collider() = default;

	virtual bool IsCollidingWithCollider(const Collider* other) = 0;
	virtual bool WillBeCollidingWithColliderOnDirection(const Vector2D<float>& direction, const Collider* other) = 0;

	virtual void OnCollisionEnter();
	virtual void OnCollisionStay();
	virtual void OnCollisionExit();

	GameObject* GetThisGameObject();
	void SetCollisionData(CollisionData incomingCollisionData);


	ColliderType _type;
	ColliderBoundary _boundary;
	bool _willBeColliding;
	CollisionData _collisionData;

private:
	GameObject* _thisGameObject;
};