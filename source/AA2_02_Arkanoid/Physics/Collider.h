#pragma once
#include "SDL.h"
#include "CollisionsHelper.h"


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

	ColliderType _type;
	ColliderBoundary _boundary;

};