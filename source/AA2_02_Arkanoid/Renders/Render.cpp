#include "Render.h"

Render::Render(SDL_Renderer* renderer, const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceSize,
	const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize)
	: _renderer(renderer), _texture(nullptr), _textureFlip(SDL_FLIP_NONE), _rotationAngleInDegrees(0), _rotationPivot({0,0})
{
	SetSourceRect(sourceStartCorner, sourceSize);
	SetDestinationRect(destinationStartCorner, destinationSize);
}

Vector2D<int> Render::GetSourceRectStart()
{
	return Vector2D<int>(_sourceRect.x, _sourceRect.y);
}

void Render::SetSourceRect(const Vector2D<int>& sourceStartCorner, const Vector2D<int>& sourceSize)
{
	_sourceRect.x = sourceStartCorner.X;
	_sourceRect.y = sourceStartCorner.Y;
	_sourceRect.w = sourceSize.X;
	_sourceRect.h = sourceSize.Y;

}

void Render::SetSourceStart(const Vector2D<int>& sourceStartCorner)
{
	_sourceRect.x = sourceStartCorner.X;
	_sourceRect.y = sourceStartCorner.Y;
}

void Render::SetDestinationRect(const Vector2D<int>& destinationStartCorner, const Vector2D<int>& destinationSize)
{
	_destinationRect.x = destinationStartCorner.X;
	_destinationRect.y = destinationStartCorner.Y;
	_destinationRect.w = destinationSize.X;
	_destinationRect.h = destinationSize.Y;
}

void Render::SetDestinationStart(const Vector2D<int>& destinationStartCorner)
{
	_destinationRect.x = destinationStartCorner.X;
	_destinationRect.y = destinationStartCorner.Y;
}

void Render::SetDestinationStart(const Vector2D<float>& destinationStartCorner)
{
	_destinationRect.x = destinationStartCorner.X;
	_destinationRect.y = destinationStartCorner.Y;
}

Vector2D<int> Render::GetDestinationSize() const
{
	return Vector2D<int>(_destinationRect.w, _destinationRect.h);
}


void Render::Init(const char* path)
{
	// Create surface
	SDL_Surface* surface = IMG_Load(path);

	// Init _texture
	_texture = SDL_CreateTextureFromSurface(_renderer, surface);

	// Delete surface
	SDL_FreeSurface(surface);
}

void Render::Rotate(const int& rotationAngleInDegrees)
{
	_rotationAngleInDegrees += rotationAngleInDegrees;
	_rotationAngleInDegrees %= 360;
	_rotationPivot.x = _destinationRect.w / 2;
	_rotationPivot.y = _destinationRect.h / 2;
}

void Render::Rotate(const int& rotationAngleInDegrees, const SDL_Point& rotationPivot)
{
	_rotationAngleInDegrees += rotationAngleInDegrees;
	_rotationAngleInDegrees %= 360;
	_rotationPivot.x = rotationPivot.x;
	_rotationPivot.y = rotationPivot.y;
}

void Render::FlipX()
{
	_textureFlip = SDL_FLIP_HORIZONTAL;
}

void Render::FlipY()
{
	_textureFlip = SDL_FLIP_VERTICAL;
}

void Render::ResetFlip()
{
	_textureFlip = SDL_FLIP_NONE;
}

void Render::SetOpacity(const int& opacity)
{
	SDL_SetTextureAlphaMod(_texture, opacity);
}
