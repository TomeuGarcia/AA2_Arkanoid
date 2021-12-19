#pragma once
#include "Render.h"
#include <SDL_ttf.h>
class Text: public Render{
	

public:
	Text(SDL_Renderer* renderer, const char* text, SDL_Color& color,const Vector2D<int>& position);
	Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position, const int& textSize);
	Text(SDL_Renderer* renderer, const char* text, SDL_Color& color, const Vector2D<int>& position,
		const char* fontPath, const int& textSize);
	~Text();
	virtual void Draw() override;
private:
	SDL_Color _color;
	char* _text;
	int _textSize;
};