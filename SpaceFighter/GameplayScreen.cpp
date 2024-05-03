
#include "GameplayScreen.h"
#include "Level.h"
#include "Level01.h"
#include "Level02.h"
#include "Ship.h"


GameplayScreen::GameplayScreen(const int levelIndex)
{
	m_pLevel = nullptr;
	switch (levelIndex)
	{
	case 0: m_pLevel = new Level01(); break;
	case 1: m_pLevel = new Level02(); break;
	}

	int score = GetScore(); 

	SetTransitionInTime(1.0f);
	SetTransitionOutTime(0.5f);

	Show();
}

void GameplayScreen::LoadContent(ResourceManager *pResourceManager)
{
	Font::SetLoadSize(20, true);
	Font* pFont = pResourceManager->Load<Font>("Fonts\\ariali.ttf");

	m_pLevel->LoadContent(pResourceManager);

	std::string text = "Score: " + score;
}


void GameplayScreen::Update(const GameTime* pGameTime)
{
	MenuItem* pItem;

	// Set the menu item colors
	/*for (int i = 0; i < GetDisplayCount(); i++)*/
	//{
		pItem = GetMenuItem(i);
		pItem->SetAlpha(GetAlpha());

		if (pItem->IsSelected()) pItem->SetColor(Color::Yellow);
		else pItem->SetColor(Color::Gray);
	//}

	MenuScreen::Update(pGameTime);
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
	pSpriteBatch->Begin();

	m_pLevel->Draw(pSpriteBatch);

	pSpriteBatch->End();
}


