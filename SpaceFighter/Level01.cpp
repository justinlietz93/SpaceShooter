

#include "Level01.h"
#include "BioEnemyShip.h"
#include "BioEnemyBoss.h"


void Level01::LoadContent(ResourceManager *pResourceManager)
{
	// Setup enemy ships
	Texture *pTexture = pResourceManager->Load<Texture>("Textures\\BioEnemyShip.png");
	Texture *pBossTexture = pResourceManager->Load<Texture>("Textures\\BioEnemyBoss.png");

	const int COUNT = 21;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55
	};

	double xBossPosition = 0.1; // Sets the boss' x position
	
	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 1.0; // start delay
	Vector2 position;
	Vector2 bossPosition;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);
		

		BioEnemyShip *pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	// Sets the starting position of the boss
	bossPosition.Set(xBossPosition * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

	BioEnemyBoss* pBioBoss = new BioEnemyBoss(); // Creates a new boss object
	pBioBoss->SetTexture(pBossTexture); // Assigns its texture
	pBioBoss->SetCurrentLevel(this); // Sets the level
	pBioBoss->Initialize(bossPosition, (float)delay + 1.3); // Initializes the boss' position
	AddGameObject(pBioBoss); // Adds the boss object to the level



	Level::LoadContent(pResourceManager);
}

