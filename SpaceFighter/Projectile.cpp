#include "Projectile.h"

// Initialize static member variable
Texture* Projectile::s_pTexture = nullptr;

// Constructor for Projectile class
Projectile::Projectile()
{
    // Set default speed to 500
    SetSpeed(500);
    // Set default damage to 1
    SetDamage(1);
    // Set default direction to upward
    SetDirection(-Vector2::UNIT_Y);
    // Set default collision radius to 9
    SetCollisionRadius(9);

    // Set drawnByLevel flag to true
    m_drawnByLevel = true;
}

// Update method for Projectile class
void Projectile::Update(const GameTime* pGameTime)
{
    // If the projectile is active
    if (IsActive())
    {
        // Calculate translation based on direction and speed
        Vector2 translation = m_direction * m_speed * pGameTime->GetTimeElapsed();
        // Translate position
        TranslatePosition(translation);

        // Get current position and texture size
        Vector2 position = GetPosition();
        Vector2 size = s_pTexture->GetSize();

        // Check if projectile is off the screen in any direction and deactivate if so
        if (position.Y < -size.Y) Deactivate();
        else if (position.X < -size.X) Deactivate();
        else if (position.Y > Game::GetScreenHeight() + size.Y) Deactivate();
        else if (position.X > Game::GetScreenWidth() + size.X) Deactivate();
    }

    // Call base class's update method
    GameObject::Update(pGameTime);
}

// Draw method for Projectile class
void Projectile::Draw(SpriteBatch* pSpriteBatch)
{
    // If the projectile is active
    if (IsActive())
    {
        // Draw the projectile
        pSpriteBatch->Draw(s_pTexture, GetPosition(), Color::White, s_pTexture->GetCenter());
    }
}

// Activate method for Projectile class
void Projectile::Activate(const Vector2& position, bool wasShotByPlayer)
{
    // Set whether the projectile was shot by the player or not
    m_wasShotByPlayer = wasShotByPlayer;
    // Set position
    SetPosition(position);

    // Call base class's activate method
    GameObject::Activate();
}

// Convert Projectile object to string
std::string Projectile::ToString() const
{
    // Return a string indicating if the projectile was shot by player or enemy along with its type
    return ((WasShotByPlayer()) ? "Player " : "Enemy ") + GetProjectileTypeString();
}

// Get collision type of the projectile
CollisionType Projectile::GetCollisionType() const
{
    // Determine collision type based on whether the projectile was shot by player or enemy, and its type
    CollisionType shipType = WasShotByPlayer() ? CollisionType::PLAYER : CollisionType::ENEMY;
    return (shipType | GetProjectileType());
}
