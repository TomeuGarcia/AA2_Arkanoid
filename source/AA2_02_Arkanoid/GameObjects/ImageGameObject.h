#pragma once
#include "GameObject.h"
#include "../Renders/Image.h"

class ImageGameObject : public GameObject {

public:
	ImageGameObject(SDL_Renderer* renderer, const char* path, const Vector2D<int>& position, const Vector2D<int>& size,
		const Vector2D<int>& sourcePosition, const Vector2D<int>& sourceSize);
	ImageGameObject(SDL_Renderer* renderer, const char* path, const Vector2D<int>& position, const Vector2D<int>& size,
		const Vector2D<int>& sourcePosition, const Vector2D<int>& sourceSize, const int& opacity);
	virtual ~ImageGameObject();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

private:
	Image* _sprite;
};