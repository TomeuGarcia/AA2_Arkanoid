#include "TextGameObject.h"

TextGameObject::TextGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, const SDL_Color& backgroundColor, const Vector2D<int>& position, const Vector2D<int>& size)
	:_text(nullptr)
{
	_text = new Text(renderer, text, color, backgroundColor, position, size);
}

TextGameObject::TextGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, const SDL_Color& backgroundColor, const Vector2D<int>& position, const Vector2D<int>& size,
	const char* fontPath, const int& textSize)
	: _text(nullptr)
{
	_text = new Text(renderer, text, color, backgroundColor, position, size, fontPath, textSize);
}

TextGameObject::~TextGameObject()
{
	delete _text;
	_text = nullptr;
}

void TextGameObject::Update(const double& elapsedTime)
{
}

void TextGameObject::Render() const
{
	_text->Draw();
}
