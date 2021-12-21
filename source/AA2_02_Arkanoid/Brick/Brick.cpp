#include "Brick.h"

Brick::Brick(const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap)
	: GameObject(Tag::BALL), BoxCollider2D(this), _sprite(nullptr),
	_spriteSourceWidthGap(spriteSourceWidthGap) 
{
	_position = Vector2D<float>(position.X + size.X / 2 - size.Y / 2, position.Y + size.Y / 2 - size.X / 2); // Position inverted after rotating 90deg
	_size = Vector2D<int>(size.Y, size.X); // Size inverted after rotating 90deg

	// Initialize _collider
	_boundary._rectBoundary = { (int)_position.X, (int)_position.Y, _size.X, _size.Y };
}


void Brick::Update(const double& elapsedTime)
{
}

void Brick::Render() const
{
	_sprite->Draw();
}


Vector2D<float> Brick::GetPosition() const 
{ 
	return _position; 
}

