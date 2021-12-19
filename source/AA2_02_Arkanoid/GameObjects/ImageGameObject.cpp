#include "ImageGameObject.h"

ImageGameObject::ImageGameObject(SDL_Renderer* renderer, const char* path, const Vector2D<int>& position, const Vector2D<int>& size,
	const Vector2D<int>& sourcePosition, const Vector2D<int>& sourceSize)
	: _sprite(nullptr)
{
	// Initializing _sprite
	_sprite = new Image(renderer, sourcePosition, sourceSize, position, size);
	_sprite->Init(path);
}

ImageGameObject::ImageGameObject(SDL_Renderer* renderer, const char* path, const Vector2D<int>& position, const Vector2D<int>& size, 
	const Vector2D<int>& sourcePosition, const Vector2D<int>& sourceSize, const int& opacity)
	: _sprite(nullptr)
{
	// Initializing _sprite
	_sprite = new Image(renderer, sourcePosition, sourceSize, position, size);
	_sprite->Init(path);
	_sprite->SetOpacity(opacity);
}

ImageGameObject::~ImageGameObject()
{
	delete _sprite;
}

void ImageGameObject::Update(const double& elapsedTime)
{
}

void ImageGameObject::Render() const
{
	_sprite->Draw();
}
