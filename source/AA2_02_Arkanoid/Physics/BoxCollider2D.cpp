#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D() : Collider(nullptr, ColliderType::SQUARE)
{
}

BoxCollider2D::BoxCollider2D(GameObject* thisGameObject) 
	: Collider(thisGameObject, ColliderType::SQUARE)
{
	_boundary._rectBoundary;
}

BoxCollider2D::BoxCollider2D(GameObject* thisGameObject, const SDL_Rect& rectBoundary)
	: Collider(thisGameObject, ColliderType::SQUARE)
{
	_boundary._rectBoundary = rectBoundary;
}

BoxCollider2D::~BoxCollider2D()
{
}

bool BoxCollider2D::IsCollidingWithCollider(const Collider* other)
{
	switch (other->_type)
	{
	case ColliderType::SQUARE:
		return CollisionsHelper::IsRectInsideRect(&_boundary._rectBoundary, &other->_boundary._rectBoundary);
		break; // never executes
	default:
		return false;
		break; // never executes
	}

}

bool BoxCollider2D::WillBeCollidingWithColliderOnDirection(const Vector2D<float>& direction, const Collider* other)
{
	SDL_Rect rectBoundaryOnDirection(_boundary._rectBoundary);
	rectBoundaryOnDirection.x += direction.X;
	rectBoundaryOnDirection.y += direction.Y;

	switch (other->_type)
	{
	case ColliderType::SQUARE:
		return CollisionsHelper::IsRectInsideRect(&rectBoundaryOnDirection, &other->_boundary._rectBoundary);
		break; // never executes
	default:
		return false;
		break; // never executes
	}
}

void BoxCollider2D::SetBoundaryPosition(const Vector2D<float>& boundaryPosition)
{
	_boundary._rectBoundary.x = boundaryPosition.X;
	_boundary._rectBoundary.y = boundaryPosition.Y;
}

void BoxCollider2D::SetBoundarySize(const Vector2D<int>& boundarySize)
{
	_boundary._rectBoundary.w = boundarySize.X;
	_boundary._rectBoundary.h = boundarySize.Y;
}