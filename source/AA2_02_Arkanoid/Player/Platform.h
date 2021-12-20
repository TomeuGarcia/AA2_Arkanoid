#pragma once
#include "../GameObjects/GameObject.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"
#include "../Physics/Rigidbody2D.h"
#include "../Constants/Constants.h"


class Platform : public GameObject {

public:
	Platform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size, const float& moveSpeed);
	~Platform();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void Move(const float& elapsedTime);
	void SetMoveDirection(const Vector2D<float>& direction);
	BoxCollider2D* GetCollider() const;
	Rigidbody2D* GetRigidbody() const;

private:
	Image* _sprite;
	BoxCollider2D* _collider;
	Rigidbody2D* _rigidbody;

	Vector2D<float> _position;
	Vector2D<int> _size;
	Vector2D<float> _moveDirection;
	float _moveSpeed;
};