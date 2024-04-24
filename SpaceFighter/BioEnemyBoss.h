
#pragma once

#include "EnemyShip.h"

class BioEnemyBoss : public EnemyShip
{

public:

	BioEnemyBoss();
	virtual ~BioEnemyBoss() { }

	virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

	virtual void Update(const GameTime* pGameTime);

	virtual void Draw(SpriteBatch* pSpriteBatch);


private:

	Texture* m_pTexture = nullptr;

};