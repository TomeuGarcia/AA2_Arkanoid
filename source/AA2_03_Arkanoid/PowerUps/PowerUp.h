#pragma once
#include "../Constants/Constants.h"
#include "../Player/Platform.h"


enum class PowerUpType { MINI_LENGTH, EXTRA_LENGTH, EXTRA_SPEED, COUNT };


class PowerUp : public GameObject, public BoxCollider2D
{
public:
	PowerUp(const Vector2D<float>& position, const Vector2D<int>& size, 
		const Vector2D<float>& moveDirection, const float& moveSpeed,
		const float& effectDuration, const PowerUpType& type);
	virtual ~PowerUp() = default;

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	virtual Rigidbody2D* GetRigidbody() const override;

	virtual void DoEffect(Platform* platform) = 0;
	void DoFinishEffect(Platform* platform);
	float GetEffectDuration() const;

	PowerUpType GetType() const;
	void ResetPositionAndDirection(const Vector2D<float>& position, const Vector2D<float>& moveDirection);

protected:
	virtual void OnCollisionEnter() override;

	void Move(const double& elapsedTime);
	void NotifyPlayer(Player* player);


	Image* _sprite;
	Rigidbody2D* _rigidbody;

	Vector2D<float> _moveDirection;
	float _moveSpeed;

	float _effectDuration;
	PowerUpType _type;
};