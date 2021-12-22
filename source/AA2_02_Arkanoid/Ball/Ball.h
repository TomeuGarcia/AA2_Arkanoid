#pragma once
#include "../GameObjects/GameObject.h"
#include "../Constants/Constants.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"
#include "../Physics/Rigidbody2D.h"


enum class BallStatus{ FOLLOWING, MOVING };

class Ball : public GameObject, public BoxCollider2D {

public:
	Ball(SDL_Renderer* renderer, Vector2D<float>* position, const Vector2D<int>& size, 
		const Vector2D<float>& moveDirection, const float& moveSpeed);
	~Ball();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	virtual void OnCollisionEnter() override;


	void Move(const float& elapsedTime);
	void Follow();
	void SetMoveDirection(const Vector2D<float>& direction);
	Rigidbody2D* GetRigidbody() const;

private:
	Image* _sprite;
	Rigidbody2D* _rigidbody;

	Vector2D<float> _moveDirection;
	float _moveSpeed;
	BallStatus _ballStatus;
	Vector2D<float>** _followingPosition;
};

