#include "Platform.h"

Platform::Platform() : _sprite(nullptr) {}

Platform::~Platform()
{
	delete _sprite;
}

void Platform::InitSprite(SDL_Renderer* renderer, const Vector2D<int>& destinationStart, const Vector2D<int>& destinationEnd)
{
	_sprite = new Image(renderer, Vector2D<int>(0, 0), Vector2D<int>(60, 20), destinationStart, destinationEnd);
	_sprite->Init("../../resources/Assets/Images/platform.png");
	_sprite->Rotate(90);
}

Image* Platform::GetSprite() const
{
	return _sprite;
}
