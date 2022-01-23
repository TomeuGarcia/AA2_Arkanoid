#include "Image.h"

Image::Image(SDL_Renderer* renderer, const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceSize,
	const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize)
	: Render(renderer, sourceStartCorner, sourceSize, destinationStartCorner, destinationSize)
{}

Image::~Image() {
	SDL_DestroyTexture(_texture);
}

void Image::Draw() {
	SDL_RenderCopyEx(_renderer, _texture, &_sourceRect, &_destinationRect, _rotationAngleInDegrees, &_rotationPivot, _textureFlip);
}