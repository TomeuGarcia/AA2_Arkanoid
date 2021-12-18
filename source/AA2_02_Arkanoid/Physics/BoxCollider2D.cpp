#include "BoxCollider2D.h"

BoxCollider2D::BoxCollider2D() : Collider(ColliderType::NONE)
{
}

BoxCollider2D::BoxCollider2D(const SDL_Rect& boundaries) : Collider(ColliderType::SQUARE)
{
	_boundary._rectBoundary = boundaries;
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