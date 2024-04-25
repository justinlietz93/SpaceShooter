#include "BioEnemyBoss.h"

// Constructor for BioEnemyShip class
BioEnemyBoss::BioEnemyBoss()
{
    // Set speed to 1.2
    SetSpeed(1.3);
    // Set maximum hit points to 150
    SetMaxHitPoints(130);
    // Set collision radius to 50
    SetCollisionRadius(80);
}

// Update method for BioEnemyShip class
void BioEnemyBoss::Update(const GameTime* pGameTime)
{
    // If the ship is active
    if (IsActive())
    {
        const int PADDING = 70; // Padding to fit the boss of the screen
        const int LEFT = PADDING;
        const int RIGHT = Game::GetScreenWidth() - PADDING;
        const double MAX_HORIZ_SPEED = 3.2; // Constant for the max horizontal speed
        const double MAX_VERT_SPEED = 0.7;// Constant for the max vertical speed

        Vector2* pPosition = &GetPosition(); // Gets the position of the middle of the ship
        if (pPosition->X - GetHalfDimensions().X < LEFT) // Ensures the boss doesn't go past the left edge of the screen
        {
            // Takes the current horizontal speed, swaps the sign (+ or -), and multiplies it by the speed of the ship
            m_horizontalDirection = GetSpeed() * SwapDirection(m_horizontalDirection);
            // Increases the vertical speed by 0.3
            m_verticalDirection += 0.3;
        }
        if (pPosition->X + GetHalfDimensions().X > RIGHT) // Ensures the boss doesn't go past the right edge of the screen
        {
            m_horizontalDirection = GetSpeed() * SwapDirection(m_horizontalDirection);
            m_verticalDirection += 0.3;
        }

        // Prevents boss from going too fast for the player by setting the speed to the max allowed
        if (m_horizontalDirection > MAX_HORIZ_SPEED) { m_horizontalDirection = MAX_HORIZ_SPEED; }
        if (m_verticalDirection > MAX_VERT_SPEED) { m_verticalDirection = MAX_VERT_SPEED; }

        // Translates the position
        TranslatePosition(m_horizontalDirection, m_verticalDirection);

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

float BioEnemyBoss::SwapDirection(float x)
{
    // Swaps the negative/positive number
    return x *= -1;
}

