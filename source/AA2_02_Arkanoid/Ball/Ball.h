#pragma once
#include "../Constants/Constants.h"
#include "../Renders/Image.h"


class Ball {

public:
	Ball(const Vector2D<int>& position, const float& moveSpeed);
	~Ball();
	void InitSprite(SDL_Renderer* renderer);
	void Move(const Vector2D<int>& direction, const float& elapsedTime);
	void Draw() const;

private:
	Image* _sprite;
	Vector2D<int> _position;
	Vector2D<int> _size;
	float _moveDistance;
	float _moveSpeed;

};

