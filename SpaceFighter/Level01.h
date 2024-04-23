#pragma once

#include "Level.h"

class Level01 :	public Level
{
private:
	// Track the number of spawned enemies
	int m_enemyCount = 0;
	// Total number of enemies expected to spawn
	int m_totalEnemyCount = 0; 

public:
	
	Level01() { }

	virtual ~Level01() { }

	virtual void LoadContent(ResourceManager *pResourceManager);

	virtual void UnloadContent() { }

};

