#pragma once
#include "SDL.h"
#include "../Physics/Vector2D.h"
#include "../Physics/CollisionsHelper.h"
#include "../Renders/Image.h"
#include "../Constants/Constants.h"

class Brick 
{
public:
	Brick(const Vector2D<int>& position, const Vector2D<int>& size, const int& spriteSourceWidth);
	virtual ~Brick() = default;

	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart) = 0;
	virtual void NextSprite() = 0;
	virtual bool DoCollision() = 0; // Return true if brick is to be destroyed

	void Draw() const;
	Vector2D<int> GetPosition() const;

protected:
	Vector2D<int> _position;
	Vector2D<int> _size;
	int _spriteSourceWidth;
	Image* _sprite;

};