#pragma once
#include "../GameObjects/GameObject.h"
#include "../Constants/Constants.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"


class Ball : GameObject {

public:
	Ball(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const Vector2D<float>& moveDirection, const float& moveSpeed);
	~Ball();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void Move(const float& elapsedTime);
	void SetMoveDirection(const Vector2D<float>& direction);

private:
	Image* _sprite;
	BoxCollider2D* _collider;

	Vector2D<float> _position;
	Vector2D<int> _size;
	Vector2D<float> _moveDirection;
	float _moveSpeed;
};

