#include "CollisionManager.h"

CollisionManager CollisionManager::m_collisionManager;

void CollisionManager::Update()
{
	for (int i = 0; i < m_pCollision.size(); i++) {
		for (int j = i + 1; j < m_pCollision.size(); j++) {
			if (m_pCollision[i]->GetCoolisionId() != m_pCollision[j]->GetCoolisionId())
			{
				D3DXVECTOR2 Pos = m_pCollision[i]->GetPosition();
				D3DXVECTOR2 Size = m_pCollision[i]->GetSize();
				D3DXVECTOR2 Pos2 = m_pCollision[j]->GetPosition();
				D3DXVECTOR2 Size2 = m_pCollision[j]->GetSize();
				if (Pos.x - Size.x / 2 < Pos2.x + Size2.x / 2 &&
					Pos.x + Size.x / 2 > Pos2.x - Size2.x / 2) {
					if (Pos.y - Size.y / 2 < Pos2.y + Size2.y / 2 &&
						Pos.y + Size.y / 2 > Pos2.y - Size2.y / 2) {
						m_pCollision[i]->SetOtherCoolisionId(m_pCollision[j]->GetCoolisionId());
						m_pCollision[j]->SetOtherCoolisionId(m_pCollision[i]->GetCoolisionId());
					}
				}

			}
		}
	}
}