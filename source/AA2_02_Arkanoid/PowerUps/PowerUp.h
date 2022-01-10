#pragma once
#include "../GameObjects/GameObject.h"
#include "../Physics/BoxCollider2D.h"
#include "../Renders/Image.h"
#include "../Constants/Constants.h"
#include "../Player/Platform.h"


class PowerUp : public GameObject, public BoxCollider2D
{
public:
	PowerUp(const Vector2D<float>& position, const Vector2D<int>& size, 
		const Vector2D<float>& moveDirection, const float& moveSpeed);
	virtual ~PowerUp() = default;

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	virtual void DoEffect(Platform* platform) = 0;

protected:
	void Move(const double& elapsedTime);


	Image* _sprite;

	Vector2D<float> _moveDirection;
	float _moveSpeed;
};