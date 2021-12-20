#include "Brick.h"

Brick::Brick(const Vector2D<int>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap)
	: _sprite(nullptr), _collider(nullptr), _position(), _size(), 
	_spriteSourceWidthGap(spriteSourceWidthGap) 
{
	_position = Vector2D<int>(position.X + size.X / 2 - size.Y / 2, position.Y + size.Y / 2 - size.X / 2); // Position inverted after rotating 90deg
	_size = Vector2D<int>(size.Y, size.Y); // Size inverted after rotating 90deg
}


void Brick::Update(const double& elapsedTime)
{
}

void Brick::Render() const
{
	_sprite->Draw();
}


Vector2D<int> Brick::GetPosition() const { return _position; }

