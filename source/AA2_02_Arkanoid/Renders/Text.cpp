#include "Text.h"

Text::Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const SDL_Color& backgroundColor, const Vector2D<int>& position, const Vector2D<int>& size)
	:Render(renderer, Vector2D<int>(), Vector2D<int>(), position, size), _text(const_cast<char*>(text)), _color(color), _backgroundColor(backgroundColor), _textSize(32)
{
	TTF_Init();
	TTF_Font* font = TTF_OpenFont("../../resources/assets/fonts/sunspire.ttf",_textSize);
	SDL_Surface* surfaceMessage = TTF_RenderText_Shaded(font, _text, _color, _backgroundColor);
	_texture = SDL_CreateTextureFromSurface(_renderer, surfaceMessage);
	SDL_FreeSurface(surfaceMessage);
	TTF_SizeText(font, text, &_destinationRect.w, &_destinationRect.h);

}

Text::Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const SDL_Color& backgroundColor, const Vector2D<int>& position, const Vector2D<int>& size, const char* fontPath, const int& textSize)
	: Render(renderer, Vector2D<int>(), Vector2D<int>(), position, size), _text(const_cast<char*>(text)), _color(color), _backgroundColor(backgroundColor), _textSize(textSize)
{
	TTF_Init();
	TTF_Font* font = TTF_OpenFont(fontPath, _textSize);
	SDL_Surface* surfaceMessage = TTF_RenderText_Shaded(font, _text, _color, _backgroundColor);
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
	SDL_RenderCopyEx(_renderer, _texture, &_sourceRect, &_destinationRect, _rotationAngleInDegrees, &_rotationPivot, _textureFlip);
}
