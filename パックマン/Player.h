#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
#include "DirectInput.h"

#define PACMAN_W 50
#define PACMAN_H 50
#define MOVESPEED 5.f

#define INNTIAL_POSX 50.f
#define INNTIAL_POSY 50.f

class Player : public ObjectBase{
public:
	Player();
	~Player();
	void SetUp();
	virtual void Draw();
	virtual void Update();
	//動き
	//速さ
	//ドットを食べる
	//アイテムをとった時の挙動
	//敵に当たった時の判定
	//壁に当たった時の判定
	//壁を曲がるときの速さ（パックマンのほうが早い）
	//死んだときの挙動
	/*int GetPlayerTexture()
	{
		return m_PlayerTexture;
	}*/
	int* GetPlayerTextureOne()
	{
		return &m_PlayerTextureOne;
	}
	int* GetPlayerTextureTwo()
	{
		return &m_PlayerTextureTwo;
	}
	int *GetPlayerTextureThree()
	{
		return &m_PlayerTextureThree;
	}
private:
	int m_PlayerTextureOne;
	int m_PlayerTextureTwo;
	int m_PlayerTextureThree;
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
