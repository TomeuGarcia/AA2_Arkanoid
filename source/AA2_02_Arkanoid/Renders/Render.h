#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "../Physics/Vector2D.h"

class Render {

public:
	Render(SDL_Renderer* renderer, const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceSize,
		const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize);
	virtual ~Render() = default;

	Vector2D<int> GetSourceRectStart();

	void SetSourceRect(const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceSize);
	void SetSourceStart(const Vector2D<int>& destinationStartCorner);
	void SetDestinationRect(const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize);
	void SetDestinationStart(const Vector2D<int>& destinationStartCorner);
	void Init(const char* path);

	void Rotate(const int& rotationAngleInDegrees);
	void Rotate(const int& rotationAngleInDegrees, const SDL_Point& rotationPivot);
	void FlipX();
	void FlipY();
	void ResetFlip();

	virtual void Draw() = 0;
	virtual void Update(const double& elapsedTime) {};

protected:
	SDL_Rect _sourceRect;
	SDL_Rect _destinationRect;
	SDL_Renderer* _renderer;
	SDL_Texture* _texture;
	SDL_RendererFlip _textureFlip;
	int _rotationAngleInDegrees;
	SDL_Point _rotationPivot;
};