#pragma once
#include "GameObject.h"
#include "../Renders/Text.h"

class TextGameObject : public GameObject {

public:
	TextGameObject(SDL_Renderer* renderer,const char* text, SDL_Color& color, const Vector2D<int>& position);
	TextGameObject(SDL_Renderer* renderer,const char* text, SDL_Color& color, const Vector2D<int>& position, const int& textSize);
	TextGameObject(SDL_Renderer* renderer,const char* text, SDL_Color& color, const Vector2D<int>& position,
		const char* fontPath, const int& textSize);
	virtual ~TextGameObject();

	virtual void Update(const double& elapsedTime) override;
	virtual void Render() const override;

	void InitText();
	void SetText(const char* text);
	void SetTextSize(const int& textSize);
	void SetColor(const SDL_Color& color);
	void SetFont(const char* fontPath);

private:
	Text* _text;
};