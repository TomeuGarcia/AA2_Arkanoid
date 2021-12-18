#include "Brick.h"

Brick::Brick(const Vector2D<int>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap)
	: _sprite(nullptr), _collider(nullptr), _position(position), _size(size), 
	_spriteSourceWidthGap(spriteSourceWidthGap) 
{
}


void Brick::Update(const double& elapsedTime)
{
}

void Brick::Render() const
{
	_sprite->Draw();
}


Vector2D<int> Brick::GetPosition() const { return _position; }

