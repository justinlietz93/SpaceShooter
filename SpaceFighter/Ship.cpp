#include "Ship.h"
#include "GameplayScreen.h"
#include "Level.h"
#include "Level01.h"
#include "Level02.h"

// Initialize score variables
int score = 0;
int highScore = 0;

void IncreaseScore() {
    score += 1;
    //std::cout << score << "\n";

    if (score > highScore) {
        highScore = score;
        // Update the high score in the file, overwrite old highscore
        std::ofstream file("highscore.txt", std::ios::trunc);
        if (file.is_open()) {
            file << highScore;
            file.close();
        }
    }
}; 

int GetScore(int score) {
    return score; 
}



// Constructor for Ship class
Ship::Ship()
{
    // Set default position to (0, 0)
    SetPosition(0, 0);
    // Set default collision radius to 10
    SetCollisionRadius(10);

    // Set default speed to 300
    m_speed = 300;
    // Set default maximum hit points to 3
    m_maxHitPoints = 3;
    // Set invulnerability status to false
    m_isInvulnurable = false;

    // Call initialization method
    Initialize();
}

// Update method for Ship class
void Ship::Update(const GameTime* pGameTime)
{
    // Iterate through each weapon and update it
    m_weaponIt = m_weapons.begin();
    for (; m_weaponIt != m_weapons.end(); m_weaponIt++)
    {
        (*m_weaponIt)->Update(pGameTime);
    }

    // Call base class's update method
    GameObject::Update(pGameTime);
}

// Method to handle when the ship is hit
void Ship::Hit(const float damage)
{
    // If ship is not invulnerable
    if (!m_isInvulnurable)
    {
        // Decrease hit points by the damage
        m_hitPoints -= damage;

        // If hit points fall below or equal to 0, deactivate the ship
        if (m_hitPoints <= 0)
        {
            GameObject::Deactivate();
            IncreaseScore( );
        }
    }
}





// Initialize method for Ship class
void Ship::Initialize()
{
    // Set hit points to maximum hit points
    m_hitPoints = m_maxHitPoints;
}

// Method to fire weapons
void Ship::FireWeapons(TriggerType type)
{
    // Iterate through each weapon and fire it
    m_weaponIt = m_weapons.begin();
    for (; m_weaponIt != m_weapons.end(); m_weaponIt++)
    {
        (*m_weaponIt)->Fire(type);
    }
}

// Method to attach a weapon to the ship
void Ship::AttachWeapon(Weapon* pWeapon, Vector2 position)
{
    // Set the attached weapon's game object to this ship
    pWeapon->SetGameObject(this);
    // Set the offset position of the weapon
    pWeapon->SetOffset(position);
    // Add the weapon to the ship's list of weapons
    m_weapons.push_back(pWeapon);
}
