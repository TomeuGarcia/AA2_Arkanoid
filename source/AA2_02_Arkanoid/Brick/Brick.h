#pragma once
#include "SDL.h"
#include "../Physics/Vector2D.h"
#include "../Physics/CollisionsHelper.h"
#include "../Renders/Image.h"
#include "../Constants/Constants.h"

class Brick 
{
public:
	Brick(const int& x, const int& y, const int& spriteSourceWidth);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd) = 0;
	virtual void NextSprite() = 0;

	Image* GetCurrentSprite() const;
	Vector2D<int> GetPosition() const;

protected:
	Vector2D<int> _position;
	Image* _currentSprite;
	Vector2D<int> _spriteSize;
	int _spriteSourceWidth;

};