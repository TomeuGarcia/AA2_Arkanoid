#pragma once
#include "Render.h"
#include <SDL_ttf.h>
class Text: public Render{
	

public:
	Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const SDL_Color& backgroundColor,const Vector2D<int>& position, const Vector2D<int>& size);
	Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const SDL_Color& backgroundColor, const Vector2D<int>& position, const Vector2D<int>& size,
		const char* fontPath, const int& textSize);
	~Text();
	virtual void Draw() override;
private:
	SDL_Color _color;
	SDL_Color _backgroundColor;
	char* _text;
	int _textSize;
};