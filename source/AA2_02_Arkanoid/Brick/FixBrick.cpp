#include "FixBrick.h"

FixBrick::FixBrick(const Vector2D<int>& position, const Vector2D<int>& size) : Brick(position, size, FIX_BRICK_SOURCE_WIDTH){}

FixBrick::~FixBrick()
{
	delete _sprite;
}

void FixBrick::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart)
{
	_sprite = new Image(renderer, FIX_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, destinationStart, _size);
	_sprite->Init("../../resources/assets/images/bricks.png");
	_sprite->Rotate(90);
}

void FixBrick::NextSprite()
{
	Vector2D<int> sourceStart = (_sprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidth, 0));
	sourceStart %= FIX_BRICK_SOURCE_TOTAL_WIDTH;

	_sprite->SetSourceStart(sourceStart);
}

bool FixBrick::DoCollision()
{
	NextSprite();
	return false;
}
