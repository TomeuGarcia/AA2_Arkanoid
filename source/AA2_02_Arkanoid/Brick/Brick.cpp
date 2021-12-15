#include "Brick.h"

Brick::Brick(const Vector2D<int>& position, const Vector2D<int>& size, const int& spriteSourceWidth)
	: _position(position), _size(size), _spriteSourceWidth(spriteSourceWidth), _sprite(nullptr) {}

Image* Brick::GetSprite() const { return _sprite; }

Vector2D<int> Brick::GetPosition() const { return _position; }

