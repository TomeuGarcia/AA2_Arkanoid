#include "TextGameObject.h"

TextGameObject::TextGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position)
	:_text(nullptr)
{
	_text = new Text(renderer, text, color, position);
}

TextGameObject::TextGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position, const int& textSize)
	: _text(nullptr)
{
	_text = new Text(renderer, text, color, position, textSize);
}

TextGameObject::TextGameObject(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position,
	const char* fontPath, const int& textSize)
	: _text(nullptr)
{
	_text = new Text(renderer, text, color, position, fontPath, textSize);
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
