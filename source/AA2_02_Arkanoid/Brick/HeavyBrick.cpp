#include "HeavyBrick.h"

HeavyBrick::HeavyBrick(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap,
	const int& points, const int& lives)
	: Brick(position, size, spriteSourceWidthGap), 	_points(points), _lifeSystem(lives) 
{
	// Initialize _sprite
	_sprite = new Image(renderer, HEAVY_BRICK_SOURCE_START, BRICK_SOURCE_SIZE, Vector2D<int>(position.X, position.Y), size);
	_sprite->Init("../../resources/assets/images/bricks.png");
	_sprite->Rotate(90);
}

HeavyBrick::~HeavyBrick()
{
	delete _sprite;
}


void HeavyBrick::NextSprite()
{
	_sprite->SetSourceStart(_sprite->GetSourceRectStart() + Vector2D<int>(_spriteSourceWidthGap, 0));
}

void HeavyBrick::GetsHit()
{
	_lifeSystem.LoseLives(1);
	if (_lifeSystem.HasNoLivesLeft()) {
		GetsDestroyed();
	}
	else {
		NextSprite();
	}	
}

void HeavyBrick::GetsDestroyed()
{
	_brickBreaksCallback(_points);
	SetActive(false);
}
