#pragma once
#include <functional>
#include "SDL.h"
#include "../GameObjects/GameObject.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"
#include "../Constants/Constants.h"

class Brick : public GameObject, public BoxCollider2D {

public:
	Brick(const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap);
	virtual ~Brick() = default;

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	virtual void OnCollisionEnter() override;


	virtual void NextSprite() = 0;
	virtual void GetsHit() = 0; // Returns true if brick is to be destroyed
	Vector2D<float> GetPosition() const;

	void SetBrickBreaksCallback(std::function<void(const int&)> brickBreaksCallback);

protected:
	Image* _sprite;

	int _spriteSourceWidthGap;

	std::function<void(const int&)> _brickBreaksCallback;
};