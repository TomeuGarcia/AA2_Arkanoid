#include "Brick.h"

Brick::Brick(const Vector2D<int>& position, const Vector2D<int>& size, const int& spriteSourceWidth)
	: _position(position), _size(size), _spriteSourceSize(BRICK_SOURCE_SIZE), _spriteSourceWidth(spriteSourceWidth), _currentSprite(nullptr) {}

Image* Brick::GetCurrentSprite() const { return _currentSprite; }

Vector2D<int> Brick::GetPosition() const { return _position; }

