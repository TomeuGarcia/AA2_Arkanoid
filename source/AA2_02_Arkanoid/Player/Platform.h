#pragma once
#include "../Renders/Image.h"
#include "../Physics/Vector2D.h"

class Platform {

public:
	Platform();
	~Platform();
	void Init(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationSize);
	Image* GetSprite() const;

	void Move(const Vector2D<int>& direction, const float& speed);

private:
	Image* _sprite;
	Vector2D<int> _position;
	Vector2D<int> _size;
	float _moveDistance;
};