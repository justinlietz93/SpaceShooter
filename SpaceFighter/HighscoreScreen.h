
#pragma once

#include "KatanaEngine.h"

using namespace KatanaEngine;

class Level;

class HighscoreScreen : public Screen
{

public:

	HighscoreScreen();

	virtual ~HighscoreScreen() { }

	//virtual void LoadContent(ResourceManager* pResourceManager);

	//virtual void HandleInput(const InputState* pInput);

	//virtual void Update(const GameTime* pGameTime);

	virtual void Draw(SpriteBatch* pSpriteBatch);



private:

	Level* m_pLevel;




};
