#pragma once
#include "SDL.h"
#include "CollisionsHelper.h"
#include "../GameObjects/GameObject.h"


enum class CollisionStatus { NONE, ENTER, STAY, EXIT };

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

	GameObject* GetThisGameObject();
	void SetOtherCollisionCollider(Collider* otherCollisionCollider);
	void UpdateCollisionStatus();

	ColliderType _type;
	ColliderBoundary _boundary;
	bool _willBeColliding;

protected:
	virtual void OnCollisionEnter();
	virtual void OnCollisionStay();
	virtual void OnCollisionExit();

	void Update();

	GameObject* _thisGameObject;
	CollisionStatus _collisionStatus;
	Collider* _otherCollisionCollider;
};