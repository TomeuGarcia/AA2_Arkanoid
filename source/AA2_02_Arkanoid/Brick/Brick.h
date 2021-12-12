#pragma once
#include "SDL.h"
#include "../Physics/Vector2D.h"
#include "../Physics/CollisionsHelper.h"
#include "../Renders/Image.h"

class Brick 
{
protected:
	Vector2D<int> _position;
	Image* _currentSprite;
	int _spriteWidth;
	int _points;
public:
	Brick(const int &x,const int &y, const int &points);
	virtual void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destination) = 0;
};