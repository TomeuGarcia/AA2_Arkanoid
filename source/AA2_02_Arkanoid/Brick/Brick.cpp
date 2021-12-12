#include "Brick.h"

Brick::Brick(const int& x, const int& y, const int& points, const int& spriteSourceWidth)
	: _position(x,y), _points(points), _spriteSize(40, 20), _spriteSourceWidth(spriteSourceWidth), _currentSprite(nullptr) {}


