#pragma once
#include "../GameObjects/GameObject.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"
#include "../Physics/Rigidbody2D.h"
#include "../Constants/Constants.h"


class Platform : public GameObject, public BoxCollider2D {

public:
	Platform(SDL_Renderer* renderer, const Vector2D<float>& position, const Vector2D<int>& size,
		const float& moveSpeed, Vector2D<float>* grabPosition);
	~Platform();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void Move(const double& elapsedTime);
	void SetMoveDirection(const Vector2D<float>& direction);
	
	Rigidbody2D* GetRigidbody() const;
	Vector2D<float>* GetGrabPosition() const;

private:
	Image* _sprite;
	Rigidbody2D* _rigidbody;

	Vector2D<float> _moveDirection;
	float _moveSpeed;
	Vector2D<float>* _grabPosition;
};