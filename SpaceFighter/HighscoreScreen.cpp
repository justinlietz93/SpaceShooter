
#include "HighscoreScreen.h"

#include <fstream>
#include <iostream>
#include <string>
#include "Level.h"
#include "Level01.h"
#include "Level02.h"


HighscoreScreen::HighscoreScreen()
{
	
}

void ReadHighscores() {
	// Create a text string, which is used to output the text file
	std::string myText;

	// Read from the text file
	std::ifstream MyReadFile("highscore.txt");

	// Use a while loop together with the getline() function to read the file line by line
	while (getline(MyReadFile, myText)) {
		// Output the text from the file
		std::cout << myText;
	}

	// Close the file
	MyReadFile.close();
}
//
//void HighscoreScreen::LoadContent(ResourceManager* pResourceManager)
//{
//	m_pLevel->LoadContent(pResourceManager);
//}
//
//
//void HighscoreScreen::HandleInput(const InputState* pInput)
//{
//	m_pLevel->HandleInput(pInput);
//}
//
//void HighscoreScreen::Update(const GameTime* pGameTime)
//{
//	m_pLevel->Update(pGameTime);
//}

void HighscoreScreen::Draw(SpriteBatch* pSpriteBatch)
{
	pSpriteBatch->Begin();

	m_pLevel->Draw(pSpriteBatch);

	pSpriteBatch->End();
}


