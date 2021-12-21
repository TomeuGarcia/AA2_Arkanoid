#include "FixBrick.h"

FixBrick::FixBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap) 
	: Brick(position, size, spriteSourceWidthGap) 
{
	// Initialize _sprite
	_sprite = new Image(renderer, FIX_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, Vector2D<int>(position.X, position.Y), size);
	_sprite->Init("../../resources/assets/images/bricks.png");
	_sprite->Rotate(90);
}

FixBrick::~FixBrick()
{
	delete _sprite;
}


void FixBrick::NextSprite()
{
	Vector2D<int> sourceStart = (_sprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidthGap, 0));
	sourceStart %= FIX_BRICK_SOURCE_TOTAL_WIDTH;
	_sprite->SetSourceStart(sourceStart);
}

bool FixBrick::DoCollision()
{
	NextSprite();
	return false;
}
