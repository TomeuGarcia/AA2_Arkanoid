#pragma once
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

	virtual void NextSprite() = 0;
	virtual bool DoCollision() = 0; // Returns true if brick is to be destroyed
	Vector2D<float> GetPosition() const;

protected:
	Image* _sprite;

	int _spriteSourceWidthGap;
};