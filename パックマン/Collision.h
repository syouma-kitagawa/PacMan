#ifndef COLLISION_H
#define COLLISION_H

#include "d3dx9math.h"
#include <vector>

class Collision {
public:
	enum CollisionId{
		PLAYER,
		COOKIE,
		ENEMY
	};
	Collision()
	{
		m_Id = m_CollisionNum;
		m_CollisionNum++;
	};
	~Collision() {};
	int GetId()
	{
		return m_Id;
	}
	D3DXVECTOR2 GetPosition()
	{
		return m_Position;
	}
	void SetPosition(D3DXVECTOR2 Position)
	{
		m_Position = Position;
	}
	D3DXVECTOR2 GetSize()
	{
		return m_Size;
	}
	void SetSize(D3DXVECTOR2 Size)
	{
		m_Size = Size;
	}
	CollisionId GetCoolisionId()
	{
		return m_CollisionId;
	}
	void SetCoolisionId(CollisionId CoolisionId)
	{
		m_CollisionId = CoolisionId;
	}
	CollisionId GetOtherCollisionId()
	{
		return m_OtherCollisionId;
	}
	void SetOtherCoolisionId(CollisionId OtherCoolisionId)
	{
		m_OtherCollisionId = OtherCoolisionId;
	}
private:
	CollisionId m_OtherCollisionId;
	CollisionId m_CollisionId;
	D3DXVECTOR2 m_Position;
	D3DXVECTOR2 m_Size;
	static int m_CollisionNum;
	int m_Id;
};

#endif // !COLLISION_H
