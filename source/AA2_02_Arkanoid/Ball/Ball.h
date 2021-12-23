#pragma once
#include "../GameObjects/GameObject.h"
#include "../Constants/Constants.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"
#include "../Physics/Rigidbody2D.h"
#include "../Player/Platform.h"


enum class BallStatus{ FOLLOWING, MOVING };

class Ball : public GameObject, public BoxCollider2D {

public:
	Ball(SDL_Renderer* renderer, const Vector2D<int>& size, const float& moveSpeed, Platform* lastPlatform);
	~Ball();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	virtual void OnCollisionEnter() override;


	void Move(const float& elapsedTime);
	void Follow();
	void SetMoveDirection(const Vector2D<float>& direction);
	Rigidbody2D* GetRigidbody() const;
	void StartMoving();
	void StartFollowing(Platform* platformToFollow);
	void SetLastPlatform(Platform* lastPlatform);

private:
	Image* _sprite;
	Rigidbody2D* _rigidbody;

	Vector2D<float> _moveDirection;
	float _moveSpeed;
	BallStatus _ballStatus;
	Vector2D<float>* _followingPosition;
	Platform* _lastPlatform;
};

