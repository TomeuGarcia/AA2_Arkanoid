#pragma once
#include "../Constants/Constants.h"
#include "../Renders/Image.h"


class Ball {

public:
	Ball(const Vector2D<float>& position, const float& moveSpeed);
	~Ball();
	void InitSprite(SDL_Renderer* renderer);
	void Move(const Vector2D<float>& direction, const float& elapsedTime);
	void Draw() const;

private:
	Image* _sprite;
	Vector2D<float> _position;
	Vector2D<int> _size;
	float _moveDistance;
	float _moveSpeed;

};

