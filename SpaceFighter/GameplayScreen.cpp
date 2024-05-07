
#include "GameplayScreen.h"
#include "Level.h"
#include "Level01.h"


GameplayScreen::GameplayScreen(const int levelIndex)
{
	m_pLevel = nullptr;
	switch (levelIndex)
	{
	case 0: m_pLevel = new Level01(); break;
	}

	SetTransitionInTime(1.0f);
	SetTransitionOutTime(0.5f);

	Show();
}

void GameplayScreen::LoadContent(ResourceManager *pResourceManager)
{
	m_pLevel->LoadContent(pResourceManager);
	Font::SetLoadSize(40, true);
	font = pResourceManager->Load<Font>("Fonts/ariali.ttf");
	if (!font) {
		std::cerr << "Failed to load font.\n";
	}
	//while 
	int scoreDisplay = GetScore(score);
	textPosition = Vector2(50, 850);
	textColor = Color::White;

	text = "Score: " + std::to_string(scoreDisplay);
}


/*void OnHighScoreSelect(MenuScreen* pScreen)
{
	//
	pScreen->GetScreenManager()->AddScreen(new GameplayScreen());
}*/

void GameplayScreen::HandleInput(const InputState *pInput)
{
	m_pLevel->HandleInput(pInput);
}

void GameplayScreen::Update(const GameTime *pGameTime)
{
	m_pLevel->Update(pGameTime);
}

void GameplayScreen::Draw(SpriteBatch *pSpriteBatch)
{
	if (pSpriteBatch && font) {
		if (!font || text.empty()) {
			std::cerr << "Font is not loaded or text is empty, cannot draw text.\n";
			return;
		}

		pSpriteBatch->Begin();

		if (m_pLevel) {
			m_pLevel->Draw(pSpriteBatch);
		}

		pSpriteBatch->DrawString(font, &text, textPosition, textColor, TextAlign::LEFT, 0.0f);

		pSpriteBatch->End();
	}

		//void SpriteBatch::DrawString(const Font * pFont, std::string * text, const Vector2 position,
		//	const Color color, const TextAlign alignment, const float drawDepth)
}


