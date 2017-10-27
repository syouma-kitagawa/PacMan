#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include "Collision.h"
#include "Player.h"
#include <vector>

class CollisionManager
{
public:
	~CollisionManager();
	void AddCollision(Collision* pCollision)
	{
		m_pCollision.push_back(pCollision);
	}

	void RemoveCollision(Collision* pCollision)
	{
		for (int i = 0; i < m_pCollision.size(); i++) {
			if (pCollision->GetId() == m_pCollision[i]->GetId()) {
				m_pCollision.erase(m_pCollision.begin() + i);
			}
		}
	}
	void Update();
	static CollisionManager* GetcollisionManager() { return m_collisionManager; };
private:
	CollisionManager(){};
	static CollisionManager* m_collisionManager;
	std::vector<Collision*> m_pCollision;
};

#endif 

