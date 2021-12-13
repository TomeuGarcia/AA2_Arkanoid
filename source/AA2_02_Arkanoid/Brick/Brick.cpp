#include "Brick.h"

Brick::Brick(const int& x, const int& y, const int& spriteSourceWidth)
	: _position(x,y), _spriteSize(BRICK_SOURCE_SIZE), _spriteSourceWidth(spriteSourceWidth), _currentSprite(nullptr) {}

Image* Brick::GetCurrentSprite() const { return _currentSprite; }

Vector2D<int> Brick::GetPosition() const { return _position; }

