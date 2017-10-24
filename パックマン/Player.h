#ifndef PLAYER_H
#define PLAYER_H
#include "CharObject.h"
#include "DirectInput.h"
#include "Game.h"

#define PACMAN_W 10
#define PACMAN_H 10
#define PACMAN_TU 0.0625
#define PACMAN_TV 0.0625
#define MOVESPEED 5.f

#define INNTIAL_POSX 50.f
#define INNTIAL_POSY 50.f

class Player : public CharObjectBase{
public:
	Player();
	virtual ~Player();
	virtual void Draw();
	virtual void Update();

	enum Direction {
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	//動き
	//速さ
	//ドットを食べる
	//アイテムをとった時の挙動
	//敵に当たった時の判定
	//壁に当たった時の判定
	//壁を曲がるときの速さ（パックマンのほうが早い）
	//死んだときの挙動
	int* GetPlayerTexture()
	{
		return &m_PlayerTexture;
	}
private:
	int m_PlayerTexture;
	Direction m_Directon;
	float m_Tu;
	float m_Tv;
	D3DXVECTOR2 m_Pos;
	KEYSTATE m_Key[KEYMAX] = { KEY_OFF };
};

class Enemy {
public:
	//動き
	//速さ(敵のほうが少し早い)
	//アイテムをとられた時の挙動
	//プレイヤーに当たった時の挙動
	//壁に当たった時の判定
	//壁を曲がるときの速さ（パックマンのほうが早い）
	//プレイヤーに食べられた時の挙動
	//指定されたルートに行く
};
#endif 
