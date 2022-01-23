#pragma once
#include "Render.h"
#include <SDL_ttf.h>


class Text: public Render{

public:
	Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const Vector2D<int>& position);
	Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const Vector2D<int>& position, 
		const int& textSize);
	Text(SDL_Renderer* renderer, const char* text, const SDL_Color& color, const Vector2D<int>& position,
		const char* fontPath, const int& textSize);
	~Text();

	virtual void Draw() override;

	void InitText();
	void SetText(const char* text);
	void SetTextSize(const int& textSize);
	void SetColor(const SDL_Color& color);
	void SetFont(const char* fontPath);

private:
	char* _text;
	int _textSize;
	SDL_Color _color;
	char* _fontPath;

};