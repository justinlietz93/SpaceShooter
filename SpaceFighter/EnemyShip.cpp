#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
    // Initialize enemy ship with default parameters
     // Set maximum hit points to 1
    SetMaxHitPoints(1);
    // Set collision radius to 20
    SetCollisionRadius(20);
}


// Update method for EnemyShip
void EnemyShip::Update(const GameTime* pGameTime)
{
    // If there's a delay before activation, count down
    if (m_delaySeconds > 0)
    {
        // Decrement delay time
        m_delaySeconds -= pGameTime->GetTimeElapsed();

        // If delay time has elapsed, activate the enemy ship
        if (m_delaySeconds <= 0)
        {
            // Activate the enemy ship
            GameObject::Activate();
        }
    }

    // If the enemy ship is active
    if (IsActive())
    {
        // Increment activation time
        m_activationSeconds += pGameTime->GetTimeElapsed();

        // If activation time exceeds 2 seconds and the ship is not on screen, deactivate it
        if (m_activationSeconds > 2 && !IsOnScreen())
        {
            // Deactivate the enemy ship
            Deactivate();
        }
    }
    // Call the base class's update method
    Ship::Update(pGameTime);
}

// Initialize method for EnemyShip
void EnemyShip::Initialize(const Vector2 position, const double delaySeconds)
{
    // Set the position of the enemy ship
    SetPosition(position); 
    // Set the delay before activation
    m_delaySeconds = delaySeconds; 
    
    // Call the base class's initialize method
    Ship::Initialize();
}

// Method to handle when the enemy ship is hit
void EnemyShip::Hit(const float damage)
{
    // Call the base class's hit method
    Ship::Hit(damage); 
}
