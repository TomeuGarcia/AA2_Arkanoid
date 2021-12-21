#include "Wall.h"

Wall::Wall(const Vector2D<float>& position, const Vector2D<int>& size)
	: GameObject(Tag::WALL), BoxCollider2D(this, {(int)position.X, (int)position.Y, size.X, size.Y})
{
}

Wall::~Wall()
{
}

void Wall::Update(const double& elapsedTime)
{
}

void Wall::Render() const
{
}
