
#pragma once

#include "KatanaEngine.h"
#include "PlayerShip.h"
#include "CollisionManager.h"

using namespace KatanaEngine;

class GameplayScreen;

class Level
{

public:

	Level();
	virtual ~Level();

	virtual void LoadContent(ResourceManager* pResourceManager);

	virtual void UnloadContent() = 0; // Pure Virtual

	virtual void HandleInput(const InputState* pInput);

	virtual void Update(const GameTime* pGameTime);

	virtual void Draw(SpriteBatch* pSpriteBatch);

	virtual void AddGameObject(GameObject* pGameObject) { m_gameObjects.push_back(pGameObject); }

	virtual void UpdateSectorPosition(GameObject* pGameObject);

	virtual void SetGameplayScreen(GameplayScreen* pGameplayScreen) { m_pGameplayScreen = pGameplayScreen; }

	template <typename T>
	T* GetClosestObject(const Vector2 position, const float range)
	{
		float squaredRange = range * range;
		if (range <= 0)
		{
			int w = Game::GetScreenWidth();
			int h = Game::GetScreenHeight();
			squaredRange = w * w + h * h;
		}
		float squaredDistance;

		std::vector<GameObject*>::iterator m_it = m_gameObjects.begin();
		T* pClosest = nullptr;

		for (; m_it != m_gameObjects.end(); m_it++)
		{
			GameObject* pGameObject = *m_it;
			if (pGameObject->IsActive()) continue;

			squaredDistance = (position - pGameObject->GetPosition()).LengthSquared();
			if (squaredDistance < squaredRange)
			{
				T* pObject = dynamic_cast<T*>(pGameObject);
				if (pObject)
				{
					pClosest = pObject;
					squaredRange = squaredDistance;
				}
			}
		}

		return pClosest;
	}


protected:

	virtual CollisionManager* GetCollisionManager() { return m_pCollisionManager; }

	virtual void SetBackgroundAudio(AudioSample* pAudio) { m_pAudio = pAudio; }

	virtual AudioSample* GetBackgroundAudio() { return m_pAudio; }

private:

	// Stuff for background image scrolling effect
	float m_verticalMovement = 0.0f;
	// Adjust according to frame rate
	const float FRAME_RATE = 60.0f;
	const float TIME_STEP = 1.0f / FRAME_RATE;

	CollisionManager* m_pCollisionManager = nullptr;

	GameplayScreen* m_pGameplayScreen = nullptr;

	AudioSample* m_pAudio = nullptr;

	AudioSample* m_pBackgroundMusic = nullptr;

	std::vector<GameObject*>* m_pSectors;

	Vector2 m_sectorCount;
	Vector2 m_sectorSize;

	unsigned int m_totalSectorCount;

	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*>::iterator m_gameObjectIt;

	PlayerShip* m_pPlayerShip;
	std::vector<Projectile*> m_projectiles;

	Texture* m_backgroundTexture = nullptr;

	void CheckCollisions(std::vector<GameObject*>& sector);

	virtual Vector2 GetSectorCount() const { return m_sectorCount; }

	virtual Vector2 GetSectorSize() const { return m_sectorSize; }

	virtual unsigned int GetTotalSectorCount() const { return m_totalSectorCount; }

	virtual std::vector<GameObject*>* GetSectors() { return m_pSectors; }

};
