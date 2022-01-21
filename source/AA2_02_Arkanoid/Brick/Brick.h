#pragma once
#include <functional>
#include "SDL.h"
#include "../GameObjects/GameObject.h"
#include "../Renders/Image.h"
#include "../Renders/AnimatedImage.h"
#include "../Physics/BoxCollider2D.h"
#include "../Constants/Constants.h"

class Brick : public GameObject, public BoxCollider2D {

public:
	Brick(const Vector2D<float>& position, const Vector2D<int>& size, const int& spriteSourceWidthGap);
	virtual ~Brick() = default;

	virtual void Render() const override;

	Vector2D<float> GetPosition() const;
	void SetBrickBreaksCallback(std::function<void(const Vector2D<float>, const int&)> brickBreaksCallback);

	virtual void GetsHit() = 0;

protected:

	AnimatedImage* _animatedSprite;

	int _spriteSourceWidthGap;
	bool _playingAnimation;

	std::function<void(const Vector2D<float>, const int&)> _brickBreaksCallback;
};