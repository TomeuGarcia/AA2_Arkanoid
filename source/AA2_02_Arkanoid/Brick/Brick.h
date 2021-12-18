#pragma once
#include "SDL.h"
#include "../GameObjects/GameObject.h"
#include "../Renders/Image.h"
#include "../Physics/BoxCollider2D.h"
#include "../Constants/Constants.h"

class Brick : public GameObject {

public:
	Brick(const Vector2D<int>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap);
	virtual ~Brick() = default;

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	virtual void NextSprite() = 0;
	virtual bool DoCollision() = 0; // Returns true if brick is to be destroyed
	Vector2D<int> GetPosition() const;

protected:
	Image* _sprite;
	BoxCollider2D* _collider;

	Vector2D<int> _position;
	Vector2D<int> _size;
	int _spriteSourceWidthGap;
	
};