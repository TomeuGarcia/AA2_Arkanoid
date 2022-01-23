#include "Text.h"

Text::Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const Vector2D<int>& position)
	: Render(renderer, Vector2D<int>(), Vector2D<int>(), position, Vector2D<int>()), 
	_text(const_cast<char*>(text)), _color(color), _textSize(36), _fontPath(const_cast<char*>("../../resources/assets/fonts/sunspire.ttf"))
{
	InitText();
}

Text::Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const Vector2D<int>& position, 
	const int& textSize)
	: Render(renderer, Vector2D<int>(), Vector2D<int>(), position, Vector2D<int>()), 
	_text(const_cast<char*>(text)), _color(color), _textSize(textSize), _fontPath(const_cast<char*>("../../resources/assets/fonts/sunspire.ttf"))
{
	InitText();
}

Text::Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const Vector2D<int>& position, 
	const char* fontPath, const int& textSize)
	: Render(renderer, Vector2D<int>(), Vector2D<int>(), position, Vector2D<int>()), 
	_text(const_cast<char*>(text)), _color(color), _textSize(textSize), _fontPath(const_cast<char*>(fontPath))
{
	InitText();
}

Text::~Text()
{
	SDL_DestroyTexture(_texture);
}


void Text::Draw()
{
	SDL_RenderCopyEx(_renderer, _texture, nullptr, &_destinationRect, _rotationAngleInDegrees, &_rotationPivot, _textureFlip);
}


void Text::SetText(const char* text)
{
	_text = const_cast<char*>(text);
}

void Text::SetTextSize(const int& textSize)
{
	_textSize = textSize;
}

void Text::SetColor(const SDL_Color& color)
{
	_color = color;
}

void Text::SetFont(const char* fontPath)
{
	_fontPath = const_cast<char*>(fontPath);
}

void Text::InitText()
{
	TTF_Font* font = TTF_OpenFont(_fontPath, _textSize);
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, _text, _color);
	_texture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	TTF_SizeText(font, _text, &_destinationRect.w, &_destinationRect.h);
}
