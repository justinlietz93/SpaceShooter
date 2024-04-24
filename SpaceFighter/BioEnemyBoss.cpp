#include "BioEnemyBoss.h"

// Constructor for BioEnemyShip class
BioEnemyBoss::BioEnemyBoss()
{
    // Set speed to 150
    SetSpeed(75);
    // Set maximum hit points to 1
    SetMaxHitPoints(30);
    // Set collision radius to 20
    SetCollisionRadius(50);
}

// Update method for BioEnemyShip class
void BioEnemyBoss::Update(const GameTime* pGameTime)
{
    // If the ship is active
    if (IsActive())
    {
        // Calculate horizontal movement based on sine wave
        float x = sin(pGameTime->GetTotalTime() * Math::PI + GetIndex());
        x *= GetSpeed() * pGameTime->GetTimeElapsed() * 1.4f;
        // Translate position horizontally
        TranslatePosition(x, GetSpeed() * pGameTime->GetTimeElapsed());

        // If the ship is not on screen, deactivate it
        if (!IsOnScreen())
        {
            Deactivate();
        }
    }

    // Call base class's update method
    EnemyShip::Update(pGameTime);
}

// Draw method for BioEnemyShip class
void BioEnemyBoss::Draw(SpriteBatch* pSpriteBatch)
{
    // If the ship is active
    if (IsActive())
    {
        // Draw the ship rotated by 180 degrees
        pSpriteBatch->Draw(m_pTexture, GetPosition(), Color::White, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
    }
}
