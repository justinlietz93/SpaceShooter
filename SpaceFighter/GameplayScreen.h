
#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

// Global score variables
extern int score;
extern int highScore;

class Level;

class GameplayScreen : public Screen
{

public:

	GameplayScreen(const int levelIndex = 0);

	virtual ~GameplayScreen() { }

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void HandleInput(const InputState *pInput);

	virtual void Update(const GameTime *pGameTime);

	virtual void Draw(SpriteBatch *pSpriteBatch);

	//virtual int GetScore();


private:

	Level* m_pLevel;

	Font* font;

	std::string text;

	Vector2 textPosition;

	Color textColor;

};
