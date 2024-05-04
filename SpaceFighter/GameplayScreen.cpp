
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

	int score = GetScore(); 

	SetTransitionInTime(1.0f);
	SetTransitionOutTime(0.5f);

	Show();
}

void GameplayScreen::LoadContent(ResourceManager *pResourceManager)
{
	m_pLevel->LoadContent(pResourceManager);
	Font::SetLoadSize(20, true);
	font = pResourceManager->Load<Font>("Fonts/ariali.ttf");
	textPosition = Vector2(100, 100);
	textColor = Color::White;
}


//void GameplayScreen::Update(const GameTime* pGameTime)
//{
//	MenuItem* pItem;
//
//	// Set the menu item colors
//	/*for (int i = 0; i < GetDisplayCount(); i++)*/
//	//{
//		pItem = GetMenuItem(i);
//		pItem->SetAlpha(GetAlpha());
//
//		if (pItem->IsSelected()) pItem->SetColor(Color::Yellow);
//		else pItem->SetColor(Color::Gray);
//	//}
//
//	MenuScreen::Update(pGameTime);
//}



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
		pSpriteBatch->Begin();

		if (m_pLevel) {
			m_pLevel->Draw(pSpriteBatch);
		}

		//pSpriteBatch->DrawString(font, &text, textPosition, textColor, TextAlign::LEFT, 0.0f);

		pSpriteBatch->End();
	}
}


