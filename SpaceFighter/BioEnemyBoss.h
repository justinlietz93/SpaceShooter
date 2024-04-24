
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

	virtual float SwapDirection(float x);


private:

	float m_horizontalDirection = 2;
	float m_verticalDirection = 0;

	Texture* m_pTexture = nullptr;

};