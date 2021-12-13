#pragma once
#include "../Renders/Image.h"

class Platform {

public:
	Platform();
	~Platform();
	void InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd);
	Image* GetSprite() const;

private:
	Image* _sprite;

};