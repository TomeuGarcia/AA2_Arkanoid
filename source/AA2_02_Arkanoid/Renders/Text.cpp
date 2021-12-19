#include "Text.h"

Text::Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position)
	:Render(renderer, Vector2D<int>(), Vector2D<int>(), position, Vector2D<int>()), _text(const_cast<char*>(text)), _color(color), _textSize(36)
{
	TTF_Font* font = TTF_OpenFont("../../resources/assets/fonts/sunspire.ttf",_textSize);
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, _text, _color);
	_texture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	TTF_SizeText(font, text, &_destinationRect.w, &_destinationRect.h);
}

Text::Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position, const int& textSize)
	:Render(renderer, Vector2D<int>(), Vector2D<int>(), position, Vector2D<int>()), _text(const_cast<char*>(text)), _color(color), _textSize(textSize)
{
	TTF_Font* font = TTF_OpenFont("../../resources/assets/fonts/sunspire.ttf", _textSize);
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, _text, _color);
	_texture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	TTF_SizeText(font, text, &_destinationRect.w, &_destinationRect.h);
}

Text::Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position,
	const char* fontPath, const int& textSize)
	: Render(renderer, Vector2D<int>(), Vector2D<int>(), position, Vector2D<int>()), _text(const_cast<char*>(text)), _color(color), _textSize(textSize)
{
	TTF_Font* font = TTF_OpenFont(fontPath, _textSize);
	SDL_Surface* surfaceMessage = TTF_RenderText_Blended(font, _text, _color);
	_texture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	TTF_SizeText(font, text, &_destinationRect.w, &_destinationRect.h);
}

Text::~Text()
{
	SDL_DestroyTexture(_texture);
}



void Text::Draw()
{
	SDL_RenderCopyEx(_renderer, _texture, nullptr, &_destinationRect, _rotationAngleInDegrees, &_rotationPivot, _textureFlip);
}
