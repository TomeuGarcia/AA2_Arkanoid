#pragma once
#include "Render.h"

class Image : public Render
{

public:
	Image(SDL_Renderer* renderer, const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceSize,
		const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize);
	~Image();
	virtual void Draw() override;

};

