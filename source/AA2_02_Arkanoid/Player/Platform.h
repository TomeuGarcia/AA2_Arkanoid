#pragma once
#include "../Renders/Image.h"
#include "../Physics/Vector2D.h"
#include "../Constants/Constants.h"

class Platform {

public:
	Platform();
	~Platform();
	void Init(SDL_Renderer* renderer, const Vector2D<float>& destinationStart, const Vector2D<int>& destinationSize, const int& moveSpeed);
	void Draw() const;
	void Move(const Vector2D<float>& direction, const float& elapsedTime);

private:
	Image* _sprite;
	Vector2D<float> _position;
	Vector2D<int> _size;
	float _moveDistance;
	float _moveSpeed;
};